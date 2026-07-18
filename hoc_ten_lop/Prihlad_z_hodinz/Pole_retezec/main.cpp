#include <iostream>
#include <vector>


void vypisPole(std::vector <int> pole, int size);
int nejmensi (std::vector <int> pole,int size);
void napln_pole(std::vector <int>& pole,int size);

int main(){
    srand(time(0));
    int n;
    std::cout<<"nhap vao size cua ban: ";;
    std::cin>> n;
    std::vector <int> pole;
    napln_pole(pole,n);
    vypisPole(pole,n);
    std::cout<<"So be nhat trong mang la: ["<<nejmensi(pole,n)<<"]."<<std::endl;


    return 0;
}

void napln_pole(std::vector <int>& pole,int size){
    for (int i = 0; i < size; i++){
        int x = rand()%91+10;
        pole.push_back(x);
    }
    


}


void vypisPole(std::vector <int> pole, int size){
    std::cout<<"Mang cua ban la: ";
    for (int i = 0; i <size; i++){
        std::cout<<"["<<pole[i]<<"] ";
    }std::cout<<std::endl;
}

int nejmensi(std::vector <int> pole, int size){
    int index_min =0;
    for (int i = 0; i <size ; i++){
        if (pole[i] < pole[index_min]){
            index_min = i;
        }
    }
    return pole[index_min];
}