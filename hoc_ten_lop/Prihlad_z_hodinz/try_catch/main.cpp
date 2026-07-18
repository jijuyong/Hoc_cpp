#include <iostream>
#include <ios>// pro std::fixed a std::setprecision

using namespace std;

void atm (int* so_du){
    int so_tien_muon_rut=0;

    do{
        try
        {
            cout<<"________________________________________________"<<endl;
            cout<<"ban muon rut bao nhieu tien: ";
            cin>> so_tien_muon_rut;
            if (so_tien_muon_rut<0){
            cout<<"________________________________________________"<<endl;
            throw runtime_error("so tien ban muon rut la so am, moi nhap lai");
            }else if (so_tien_muon_rut>*so_du){
                cout<<"________________________________________________"<<endl;
                throw runtime_error("so du khong du, moi nhap lai");
            }
            *so_du = *so_du - so_tien_muon_rut;
            cout<<"________________________________________________"<<endl;
            cout<<"rut tien thanh cong, so du hien tai la: "<<*so_du<<endl; 
            break;
        }
        catch(const exception& e){
            std::cerr << e.what() << '\n';
        }
    } while (so_tien_muon_rut<0|| so_tien_muon_rut> *so_du);   

    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"ban co muon tiep tuc rut tien khong?: co/khong: ";
    string lua_chon;
    getline(cin>>ws,lua_chon);
    if (lua_chon =="co"){
        atm(so_du);
    }else exit(0);
    
    
}

int main (){


    int a,b;
    try{
        cout<<"zadej a: ";
        cin>>a;

        cout<<"zadej b: ";
        cin>>b;
        if (b==0 || a==0) throw runtime_error("khong the chia cho 0");
        cout<<"vysledek: "<<((double)a/b)<<endl; 
    }
    catch( exception& e)
    {
        cerr << e.what() << '\n';
    }

    int so_du = 10000;
    cout<<"so tien hien tai cua ban la: "<<so_du<<endl;

    atm(&so_du);

    return 0;
    

    

}