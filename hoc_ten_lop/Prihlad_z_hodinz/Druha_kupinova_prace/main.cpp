#include <iostream>
#include <string>

class Ship{
    private:
        int north,east;
        char direction;

        void move(char, int);
        void move(int);
    public:
        Ship(int north,int east,char direction){
            this->north = north;
            this->east = east;
            this->direction = direction;
        };
    
        void navigate (char, int);
        void info();
        

};

int main(){
    Ship lod1 (0,0,'E');
    lod1.info();


    std::string input = "S10";
    char command = input[0];
    int value = stoi(input.substr(1));
    std::cout<< command<<", "<<value<<std::endl;

    return 0;
}

// void Ship:: rotate(char direction, int value){
//     std::string direction = "NESW";
//     int dir_index = direction.find
    
// }


void Ship:: move(int value){
    move(direction,value);
}

void Ship::move(char direction, int value){
    switch (direction)
    {
    case 'N':
        north+=value;
        break;
    case 'S':
        north+=value;
        break;
    case 'E':
        east+=value;
        break;
    case 'W':
        east+=value;
        break;
    default:
        break;
    }
}

