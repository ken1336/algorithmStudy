#include<iostream>
#include<vector>
#include<memory>


class subDirectory;

class Directory{

    public:
    
    Directory(std::string name) : dirName(name){}

    void showSubDirectory(Directory dir){
        std::cout<<"this directory name: "<<dir.dirName<<std::endl;
        
            for(auto &i : children){
                std::cout<<"/"<<i.dirName<<std::endl;
                if(!i.children.empty())
                showSubDirectory(i);
            }
        
        
    }

    void addSubDirectory(SubDirectory& sub){
        sub.setParent(std::make_shared<Directory>(this));
        children.push_back(sub);
    }


    protected:
    std::string dirName;
    std::vector<Directory> children;
};


class SubDirectory : public Directory{
    public:
    SubDirectory(std::string name) : Directory(name){
        
    }
    //SubDirectory()
    void setParent(std::shared_ptr<Directory> parent){
        this->parent = parent;
    }
    private:
    std::shared_ptr<Directory> parent;
    
};



 void cmd_mkdir(){

    } 
    void cmd_cp(){

    }
    void cmd_rm(){

    }
int main(){

    
    Directory dir("/");

    subDirectory dir1("a");
    subDirectory dir2("b");
    subDirectory dir3("c");
    
    dir.addSubDirectory(dir1);
    dir.addSubDirectory(dir2);
    dir1.addSubDirectory(dir3);
    dir.showSubDirectory(dir);

    return 0;
}