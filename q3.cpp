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
    std::string dirName;
    virtual ~Directory() = default;
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
        auto pp = shared_from_this();
        std::stack<std::string> nameStack;

        while(pp){
            nameStack.push(pp->dirName);
            std::cout<<pp->dirName<<std::endl;
            if(auto temp = std::dynamic_pointer_cast<SubDirectory>(pp)){
                pp = temp->parent;
            }else{
                pp = NULL;
            }
        }
        
        while(!nameStack.empty()){
            auto & tt = nameStack.top();
            std::cout<<"/"<<tt;
            nameStack.pop();

        }
        std::cout<<std::endl;
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

    auto dir = std::make_shared<Directory>("");

    auto dir1 = std::make_shared<SubDirectory>("aa");
    auto dir2 = std::make_shared<SubDirectory>("bb");
    auto dir3 = std::make_shared<SubDirectory>("cc");

    dir->addSubDirectory(dir1);
    dir->addSubDirectory(dir2);
    dir2->addSubDirectory(dir3);

     
    dir3->showPath();
    //dir->showSubDirectory();

    return 0;
}