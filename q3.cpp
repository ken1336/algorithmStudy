#include <iostream>
#include <vector>
#include <memory>
#include <stack>
#include<string>
#include<sstream>
#include<list>
#include<map>
#include<assert.h>

class SubDirectory;


static std::list<std::string> tokenize_getline(const std::string& data, const char delimiter = ' ') {
	std::list<std::string> result;
	std::string token;
	std::stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}
class Directory : public std::enable_shared_from_this<Directory>
{

public:
    Directory(std::string name) : dirName(name) {}
    void showSubDirectory();
    void addSubDirectory(std::shared_ptr<SubDirectory> sub);
    void addSubDirectory(const std::string name) {
        addSubDirectory(std::make_shared<SubDirectory>(name));
        }
    std::shared_ptr<Directory> findByPath(std::string path);
    std::list<std::string> substringUnderRoot(const std::string& path, const char delimiter = ' ');
    std::string dirName;
    virtual ~Directory() = default;

protected:
    std::map<std::string,std::shared_ptr<SubDirectory>> children;
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
        auto tmep = this->parent;

        return this->parent.lock();
    }
    void showPath();
    std::string getPath();
    virtual ~SubDirectory() = default;

private:
    std::weak_ptr<Directory> parent;
};

class CommandExecutor
{
public:
    void cmd_mkdir(std::shared_ptr<Directory> directory, std::string path, std::string name);
    void cmd_cp();
    void cmd_rm();
};
std::shared_ptr<Directory> Directory::findByPath(std::string path){
    
    auto tokenizedPath = substringUnderRoot(path,'/');
    auto pwd = shared_from_this();

    assert(tokenizedPath.size() != 0);

    for(auto & i : tokenizedPath ){
        assert(pwd->children.find(i) != pwd->children.end());
        pwd = pwd->children.at(i);    
    }
    return pwd;
}
std::list<std::string> Directory::substringUnderRoot(const std::string& path, const char delimiter )
{
    auto tempList = tokenize_getline(path,delimiter);
    tempList.pop_front();
    return tempList;
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
            pp = temp->parent.lock();
        else
            pp = nullptr;
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

    children.emplace(sub->dirName,sub);
}

void Directory::showSubDirectory()
{
    if (!std::dynamic_pointer_cast<SubDirectory>(shared_from_this()))
        std::cout<<this->dirName<<std::endl;
    
    for (auto &i : children)
    {
        i.second->showPath();
        if (!i.second->children.empty())
        {

            i.second->showSubDirectory();
        }
    }
}

void CommandExecutor::cmd_mkdir(std::shared_ptr<Directory> directory,std::string path, std::string name)
{
    std::cout<<"adding "<<name<<" to path: "<<path <<std::endl;
    auto rr = directory->findByPath(path);
    auto newDir = std::make_shared<SubDirectory>(name);
    rr->addSubDirectory(newDir);


}
void CommandExecutor::cmd_cp()
{
}
void CommandExecutor::cmd_rm()
{
}

int main()
{

    auto rootDir = std::make_shared<Directory>("/");

    auto dir1 = std::make_shared<SubDirectory>("aa");
    auto dir2 = std::make_shared<SubDirectory>("bb");
    auto dir3 = std::make_shared<SubDirectory>("cc");

    auto command = std::make_shared<CommandExecutor>();

    rootDir->addSubDirectory(dir1);
    rootDir->addSubDirectory(dir2);
    dir2->addSubDirectory(dir3);
   
    rootDir->showSubDirectory();
    command->cmd_mkdir(rootDir,dir2->getPath(),"hello");

    rootDir->showSubDirectory();
    return 0;
}