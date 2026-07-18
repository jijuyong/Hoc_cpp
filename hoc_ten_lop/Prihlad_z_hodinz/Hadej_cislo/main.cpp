#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int nahodneCislo(){
    return rand() % 100;
}

void kiemtraso(int a, int so_nguoi_choi)
{

    if (so_nguoi_choi > a)
    {
        cout << "je to mensi nez [" << so_nguoi_choi << "] " << endl;
    }
    else if (so_nguoi_choi < a)
    {
        cout << "je to vetsi nez [" << so_nguoi_choi << "] " << endl;
    }
    else if (so_nguoi_choi == a)
    {
        cout << "gratuliji, uhadli jste to." << endl;
    }

    if (so_nguoi_choi == a - 1 || so_nguoi_choi == a - 2 || so_nguoi_choi == a - 3)
    {
        cout << "je to trosku vetsi." << endl;
    }
    else if (so_nguoi_choi == a + 1 || so_nguoi_choi == a + 2 || so_nguoi_choi == a + 3)
    {
        cout << "je to trosku mensi." << endl;
    }
}

void hadej_cislo(){
    int so_cua_nguoi_choi;
    int a = nahodneCislo();
    do{
        try{
            cout << "Hadej: ";
            cin >> so_cua_nguoi_choi;
            if (so_cua_nguoi_choi>100 || so_cua_nguoi_choi<0){
                throw runtime_error("neplatna cisla, zkus znovu.");
                cout << "Hadej: ";
                cin >> so_cua_nguoi_choi;
            }else kiemtraso(a, so_cua_nguoi_choi);
        }
        catch(exception& e){
            cerr << e.what() << '\n';
        }
    } while (so_cua_nguoi_choi != a);
    cout << "Chcete hrat znovu? ano/ne: ";
    string lua_chon;
    getline(cin >> ws, lua_chon);
    if (lua_chon == "ano")
    {
        a = nahodneCislo();
        hadej_cislo();
    }
    else
        exit(0);
}

int main()
{
    srand(time(0));
    // cout<<a<<endl;
    cout << "Hadej cislo v intervalu <0,100>" << endl;
    hadej_cislo();

    return 0;
}