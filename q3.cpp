#include <iostream>
#include <vector>
#include <memory>
#include <stack>
class SubDirectory;

class Directory : public std::enable_shared_from_this<Directory>
{

public:
    Directory(std::string name) : dirName(name) {}
    void showSubDirectory();
    void addSubDirectory(std::shared_ptr<SubDirectory> sub);
    std::shared_ptr<Directory> findByName(std::string name);
    
    std::string dirName;
    virtual ~Directory() = default;

protected:
    std::vector<std::shared_ptr<SubDirectory>> children;
};


class SubDirectory : public Directory
{
public:
    SubDirectory(std::string name) : Directory(name) {}
    void setParent(std::shared_ptr<Directory> parent)
    {
        this->parent = parent;
    }
    std::shared_ptr<Directory> getParent()
    {
        return this->parent;
    }
    void showPath();
    std::string getPath();
    virtual ~SubDirectory() = default;

private:
    std::shared_ptr<Directory> parent;
};

class CommandExecutor
{
    void cmd_mkdir(std::string path, std::string name);
    void cmd_cp();
    void cmd_rm();
};


std::shared_ptr<Directory> Directory::findByName(std::string name)
{
    std::cout<<name<<std::endl;
    for (auto &i : children){
        std::cout<<name<<" ? "<<i->getPath()<<"=="<<(i->getPath() == name)<<std::endl;
        if(i->getPath() == name){
            std::cout<<"good!"<<name<<" , "<<i->getPath()<<std::endl;
            return i;
        }
    }
    return NULL;

}
void SubDirectory::showPath()
{
    
    std::cout <<getPath() <<std::endl;
}
std::string SubDirectory::getPath(){
    auto pp = shared_from_this();
    std::stack<std::string> nameStack;
    std::string pathResult = "";

    while (pp)
    {
        if (std::dynamic_pointer_cast<SubDirectory>(pp))
            nameStack.push(pp->dirName);

        if (auto temp = std::dynamic_pointer_cast<SubDirectory>(pp))
            pp = temp->parent;
        else
            pp = NULL;
    }

    while (!nameStack.empty())
    {
        auto &tt = nameStack.top();
        //std::cout << "/" << tt;
        pathResult+="/"+tt;
        nameStack.pop();
    }
    return pathResult;
}
void Directory::addSubDirectory(std::shared_ptr<SubDirectory> sub)
{

    auto pp = std::shared_ptr(shared_from_this());
    sub->setParent(pp);
    children.push_back(sub);
}

void Directory::showSubDirectory()
{
    if (!std::dynamic_pointer_cast<SubDirectory>(shared_from_this()))
        std::cout<<this->dirName<<std::endl;
    
    for (auto &i : children)
    {
        i->showPath();
        if (!i->children.empty())
        {

            i->showSubDirectory();
        }
    }
}

void CommandExecutor::cmd_mkdir(std::string path, std::string name)
{
    std::cout<<"adding "<<name<<" to path: "<<path <<std::endl;

}
void CommandExecutor::cmd_cp()
{
}
void CommandExecutor::cmd_rm()
{
}

int main()
{

    auto dir = std::make_shared<Directory>("/");

    auto dir1 = std::make_shared<SubDirectory>("aa");
    auto dir2 = std::make_shared<SubDirectory>("bb");
    auto dir3 = std::make_shared<SubDirectory>("cc");

    dir->addSubDirectory(dir1);
    dir->addSubDirectory(dir2);
    dir2->addSubDirectory(dir3);

    //dir3->showPath();
    dir->showSubDirectory();
    
    auto path = dir3->getPath();
    auto rr = dir->findByName(path);
    
    return 0;
}