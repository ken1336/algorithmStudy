#include <iostream>
#include <vector>
#include <memory>

class SubDirectory;

class Directory : public std::enable_shared_from_this<Directory>
{

public:
    Directory(std::string name) : dirName(name) {}
    void showSubDirectory();
    void addSubDirectory(std::shared_ptr<SubDirectory> sub);
    std::string dirName;
protected:
    
    std::vector<std::shared_ptr<SubDirectory>> children;
};



class SubDirectory : public Directory
{
public:
    SubDirectory(std::string name) : Directory(name){}
    void setParent(std::shared_ptr<Directory> parent){
        this->parent = parent;
    }
    std::shared_ptr<Directory> getParent(){
        return this->parent;
    }
    void showPath(){
        auto pp = this->parent;
        while(!pp){
            std::cout<<pp->dirName;
            pp = pp->parent;
        }
    }
private:
    std::shared_ptr<Directory> parent;
};



void Directory::addSubDirectory(std::shared_ptr<SubDirectory> sub)
{
    
    auto pp=std::shared_ptr(shared_from_this());
    sub->setParent(pp);
    children.push_back(sub);
    

}

void Directory::showSubDirectory()
    {
        
        std::cout<<"/"<<this->dirName<<std::endl;
        for (auto &i : children)
        {
            std::cout<<"/"<<i->dirName<<std::endl;
            if (!i->children.empty()){
                
                i->showSubDirectory();
            }
                
        }
    }

void cmd_mkdir()
{

}
void cmd_cp()
{
}
void cmd_rm()
{
}
int main()
{

    auto dir = std::make_shared<Directory>("/");

    auto dir1 = std::make_shared<SubDirectory>("a");
    auto dir2 = std::make_shared<SubDirectory>("b");
    auto dir3 = std::make_shared<SubDirectory>("c");

    dir->addSubDirectory(dir1);
    dir->addSubDirectory(dir2);
    dir2->addSubDirectory(dir3);
     
    dir3->showPath();
    //dir->showSubDirectory();

    return 0;
}