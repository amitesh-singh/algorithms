#include<iostream>
#include<string>
using namespace std;
class Maze;
class MazeBuilder
{
    public:
    virtual void BuildMaze() {}
    virtual void BuildRoom(int room){}
    virtual void BuildDoor(int roomFrom,int roomTo){}
    virtual Maze *GetMaze(){return 0;}
    protected:
    MazeBuilder()
    {
    }
};
class StandardBuilder:public  MazeBuilder
{
};
class MazeGame
{
    public:
    Maze *CreateMaze(MazeBuilder &builder)
    {
        builder.BuildMaze();
        builder.BuildRoom(1);
        builder.BuildDoor(1,2);
        return builder.GetMaze();
    }

};

int main()
{

    return 0;
}
