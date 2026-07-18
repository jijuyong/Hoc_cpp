#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctype.h>
#include <algorithm>
#include <cctype>

using namespace std;

// const int SO_LAN_THU_TOI_DA = 5;
// const int SO_LAN_THU_GIAM = 3;
// const int SO_LAN_THU_KHONG_LOI = 1;
const int DO_DAI_TEN = 50;
const int THOIGIAN_DELAY_TRA_LOI = 2000;

typedef struct{
    char ten[50];
}Player;

typedef struct{
    int so_thu_tu;
    int loai;  // 0 = văn bản, 1 = số
    string cau_thuong;
    
    // Cho câu văn bản
    vector<string> cau_tra_loi_dung_van_ban;
    // Cho câu số
    int cau_tra_loi_dung_so;
}Cau_Hoi;

typedef struct{
    string ten_cap_do;
    vector <string> cac_huong_Dan;
    vector <Cau_Hoi> danh_sach_cau_hoi;
    string duong_dan_video;
}Cap_Do;

void Dat_Mau_Chu(int mau) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mau);
}

void xoa_dong(int so_dong){
    string chuoi_xoa = "";
    for (int i = 0; i < so_dong; i++)
    {
        chuoi_xoa += "\x1B[A\x1B[2K"; // Build string
    }
    cout << chuoi_xoa; // Single output
}

string chuyen_thanh_chu_thuong(string van_ban){
    transform(van_ban.begin(),van_ban.end(),van_ban.begin(), ::tolower);
    return van_ban;
}

void mat_ma_kho_bau(vector<int> &mat_ma){
    for (int i = 0; i < 5; i++){
        int x = rand()%10;
        mat_ma.push_back(x);
    }
    
}

void in_text(const string& text, int chieu_rong){
    int in = (chieu_rong - text.length()) / 2;
    if (in > 0)
    {
        cout << string(in, ' ');
    }
    cout << text << endl;
}

void in_luat_choi(const string& text, int displayWidth, int windowWidth){
    int spaces = (windowWidth - displayWidth) / 2;
    if (spaces > 0)
    {
        for (int i = 0; i < spaces; i++)
            cout << " ";
    }
    cout << text << endl;
}

bool kiem_tra_cau_tra_loi(const string& answer_cua_player, const vector<string>& cac_cau_dung){
    string cau_thuong = chuyen_thanh_chu_thuong(answer_cua_player);
    for(const auto& cau_dung: cac_cau_dung){
        if (cau_thuong==cau_dung){
            return true;
        }
        
    }return false;
}

void tao_player (Player *player){
    Dat_Mau_Chu(13);
    char ten[DO_DAI_TEN];
    cout << "Zadej jméno svého charakteru: ";
    cin >> ten;
    strncpy_s(player->ten, ten, DO_DAI_TEN - 1);//chi them dung do_dai_ten -1, neu khong thi se bi tran
    player->ten[DO_DAI_TEN - 1] = '\0';// roi cuoi string them \0
    Sleep(2000);
    xoa_dong(1);
    in_text("∘₊✧─────✧₊∘", 192);
    in_text(player->ten, 170);
    in_text("∘₊✧─────✧₊∘", 192);
    Dat_Mau_Chu(7);
    Sleep(2000);
    cout<<endl;
}

void in_tua_de (){
    Dat_Mau_Chu(10);
    // ASCII ART
    vector<string> tua_de_game =
        {"██▓    ▄▄▄       ▄▄▄▄       ███▄ ▄███▓ ▄▄▄     ▓██   ██▓ ██░ ██ ▓█████  ███▄ ▄███▓",
        "▓██▒   ▒████▄    ▓█████▄    ▓██▒▀█▀ ██▒▒████▄    ▒██  ██▒▓██░ ██▒▓█   ▀ ▓██▒▀█▀ ██▒",
        "▒██░   ▒██  ▀█▄  ▒██▒ ▄██   ▓██    ▓██░▒██  ▀█▄   ▒██ ██░▒██▀▀██░▒███   ▓██    ▓██░",
        "▒██░   ░██▄▄▄▄██ ▒██░█▀     ▒██    ▒██ ░██▄▄▄▄██  ░ ▐██▓░░▓█ ░██ ▒▓█  ▄ ▒██    ▒██ ",
        "░██████▒▓█   ▓██▒░▓█  ▀█▓   ▒██▒   ░██▒ ▓█   ▓██▒ ░ ██▒▓░░▓█▒░██▓░▒████▒▒██▒   ░██▒",
        "░ ▒░▓  ░▒▒   ▓▒█░░▒▓███▀▒   ░ ▒░   ░  ░ ▒▒   ▓▒█░  ██▒▒▒  ▒ ░░▒░▒░░ ▒░ ░░ ▒░   ░  ░",
        "░ ░ ▒  ░ ▒   ▒▒ ░▒░▒   ░    ░  ░      ░  ▒   ▒▒ ░▓██ ░▒░  ▒ ░▒░ ░ ░ ░  ░░  ░      ░",
        "  ░ ░    ░   ▒    ░    ░    ░      ░     ░   ▒   ▒ ▒ ░░   ░  ░░ ░   ░   ░      ░   ",
        "    ░  ░     ░  ░ ░                ░         ░  ░░ ░      ░  ░  ░   ░  ░       ░   ",
        "                       ░                         ░ ░                              "};

    for(const auto& dong:tua_de_game){
        in_luat_choi(dong,82,170);
    }
    in_text("Stiskni ENTER a začni hru...", 170);
    cin.get();
    xoa_dong(2);  
    cout << endl;      
    Sleep(2000);
    Dat_Mau_Chu(7);

    vector<string> luat_choi = {
        "___| |___________________________________________________________________| |__",
        "(__   ___________________________________________________________________   __)",
        "   | |                                                                   | |",
        "   | |                  CHEMICKÁ LABORKA: CESTA ZA POKLADEM              | |",
        "   | |                                                                   | |",
        "   | | JAK HRÁT:                                                         | |",
        "   | | 1. Na krátký okamžik ti stíny dovolí spatřit zakázaný postup.     | |",
        "   | | 2. Jakmile čas vyprší, vše pohltí mlha zapomnění.                 | |",
        "   | | 3. Každá otázka je zkouškou tvé paměti i odvahy.                  | |",
        "   | | 4. Správná odpověď probudí jedno zapomenuté číslo.                | |",
        "   | | 5. Chyba otevře bránu prázdnotě a část kódu zmizí.                | |",
        "   | | 6. Teprve úplný kód dokáže zlomit pečeť pokladu.                  | |",
        "   | | 7. Selžeš-li, poklad zůstane spát v temnotě.                      | |",
        "___| |___________________________________________________________________| |__",
        "(__   ___________________________________________________________________   __)",
        "   | |                                                                   | |"};
    for(const auto& dong: luat_choi){
        in_luat_choi(dong,55,150);
    }
    in_text("Pokud jsi už četl pravidla, stiskni ENTER pro pokračování...", 175);
    cin.get();
    xoa_dong(2);
    Sleep(2000);
    xoa_dong(luat_choi.size());
    Sleep(2000);
}

int xu_ly_cau_tra_loi_sai(Player *player){
    system("start video_reakce\\explosion.mp4");
    Dat_Mau_Chu(12);
    cout<<player->ten<<", chceš znovu zkusit? (ano/ne): ";
    string cau_tra_loi;
    getline(cin>>ws,cau_tra_loi);
    cau_tra_loi = chuyen_thanh_chu_thuong(cau_tra_loi);
    Dat_Mau_Chu(7);
    if (cau_tra_loi=="ano"){
        xoa_dong(1);
        return 1;
    } else {
        cout<<"Díky za hraní! 👋🏻"<<endl;
        exit(0);
    }
    
}

void hien_thi_cau_tra_loi_dung (){
    Dat_Mau_Chu(10);
    cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
    Dat_Mau_Chu(7);
    Sleep(THOIGIAN_DELAY_TRA_LOI);
    xoa_dong(1);
}

void danh_sach_reakce(const char *file_name){

    ifstream soubor(file_name);
    string radek;
    vector<string> rce;

    if (soubor.is_open()){
        while (getline(soubor, radek)){
            rce.push_back(radek);
        }
        soubor.close();
    }
    for (auto x : rce){
        cout << x << endl;
    }
}

void hoi_xem_video(const string& duong_dan_video){
    cout << "chcete vidět reakce? (ano/ne): ";
    string cau_tra_loi;
    getline(cin>>ws,cau_tra_loi);
    cau_tra_loi = chuyen_thanh_chu_thuong(cau_tra_loi);
    xoa_dong(2);
    if (cau_tra_loi =="ano"){
        system(("start "+duong_dan_video).c_str());//c_str() - doi thanh string
        cout << "Až zavřeš video, stiskni ENTER...";
        //cin.ignore();
        cin.get();
        xoa_dong(1);
    }
    
}

int xu_ly_cau_hoi(Player *player,const Cau_Hoi& cau_hoi,int& so_lan_loi){
    Dat_Mau_Chu(11);
    cout << "── .✦Otázka "<<cau_hoi.so_thu_tu<<"✦. ──" << endl;
    Dat_Mau_Chu(7);
    if (cau_hoi.loai==0){
        cout<<cau_hoi.cau_thuong;
        string cau_tra_loi_cua_player;
        getline(cin>>ws, cau_tra_loi_cua_player);
        Sleep(THOIGIAN_DELAY_TRA_LOI);
        xoa_dong(2);
        if (kiem_tra_cau_tra_loi(cau_tra_loi_cua_player,cau_hoi.cau_tra_loi_dung_van_ban)){
            hien_thi_cau_tra_loi_dung();
            return 0;
        }else{
            if (xu_ly_cau_tra_loi_sai(player)==1){
                so_lan_loi++;

                return 1;
            }
            
        }
        
    }else if (cau_hoi.loai==1){
        cout<<cau_hoi.cau_thuong;
        int cau_tra_loi_cua_player;
        cin>>cau_tra_loi_cua_player;
        cin.ignore();
        Sleep(THOIGIAN_DELAY_TRA_LOI);
        xoa_dong(2);
        if (cau_tra_loi_cua_player== cau_hoi.cau_tra_loi_dung_so){
            hien_thi_cau_tra_loi_dung();
            return 0;
        }else{
            if (xu_ly_cau_tra_loi_sai(player)==1){
                so_lan_loi++;
                return 1;
            }
            
        }
        
    }return 1;   
}

int thuc_hien_cap_do(Player *player, const Cap_Do& cap_do,int& tong_so_loi){
    bool level_tung_sai =false;

    while (true){
        int so_loi_level =0;
        Dat_Mau_Chu(14);
        for (const auto& huong_dan : cap_do.cac_huong_Dan){
            in_luat_choi(huong_dan,55,150);
        }
        in_text("⏱️MÁŠ 15 SEKUND NA ZAPAMATOVÁNÍ ⏱️",150);
        Dat_Mau_Chu(7);
        Sleep(15000);
        xoa_dong(cap_do.cac_huong_Dan.size()+1);
        bool sai = false;
        for(const auto& cau_hoi: cap_do.danh_sach_cau_hoi){
            if (xu_ly_cau_hoi(player,cau_hoi,so_loi_level)==1){
                tong_so_loi++;
                level_tung_sai=true;
                sai =true;
                break;
            }
            
        }if (!sai){
            hoi_xem_video(cap_do.duong_dan_video);
            if (level_tung_sai){
                return 2;
            }return 0;
            
        }
        

    }
    
}

Cap_Do level1(){
    Cap_Do level;
    level.ten_cap_do = "Level 1 - Foam Apocalypse";
    level.cac_huong_Dan={
        " __| |_____________________________________________________________| |__",
        "(__   _____________________________________________________________   __)",
        "   | |                                                             | |",
        "   | |              [ ✦ Level 1 - Foam Apocalypse ✦  ]             | |",
        "   | |                                                             | |",
        "   | |  postup                                                     | |",
        "   | |  1. Bezpečnost: rukavice + brýle                            | |",
        "   | |  2. Kádinka 1: 180ml H₂O₂ peroxid vodíku, 2 lžíčka saponátu | |",
        "   | |     trochu potravinářského barviva                          | |",
        "   | |  3. Kádinka 2: 15g droždí + 3 lžíce vlažné vody, promíchat. | |",
        "   | |  4. Smíchání: nalij 2 do 1                                  | |",
        " __| |_____________________________________________________________| |__",
        "(__   _____________________________________________________________   __)",
        "   | |                                                             | |"};
    
    Cau_Hoi q1;
    q1.so_thu_tu =1;
    q1.loai = 0;
    q1.cau_thuong = "Zadejte název H₂O₂: ";
    q1.cau_tra_loi_dung_van_ban = {"peroxid vodiku","peroxid vodíku","peroxidvodiku"};

    Cau_Hoi q2;
    q2.so_thu_tu =2;
    q2.loai =1;
    q2.cau_thuong = "Kolik gramů droždí (katalyzátoru) použiješ(gram)?: ";
    q2.cau_tra_loi_dung_so =15;

    level.danh_sach_cau_hoi.push_back(q1);
    level.danh_sach_cau_hoi.push_back(q2);
    level.duong_dan_video = "video_reakce\\elephant.mp4";

    return level;
}
Cap_Do level2(){
    Cap_Do level;
    level.ten_cap_do =  "Level 2 - Midnight Neon";
    level.cac_huong_Dan = {
        "___| |_____________________________________________________________| |__",
        "(__   _____________________________________________________________   __)",
        "   | |                                                             | |",
        "   | |              [ ✦ Level 2 - Midnight Neon ✦ ]                | |",
        "   | |                                                             | |",
        "   | |postup                                                       | |",
        "   | | 1. Bezpečnost: rukavice + brýle                             | |",
        "   | | 2. Kádinka 1: Smíchej 2ml 8% chlornanu sodného (bělidla) s  | |",
        "   | |    200 ml destilované vody                                  | |",
        "   | | 3. Kádinka 2: Vezmi 0,8g hydroxidu sodného + 0,1g luminolu  | |",
        "   | | 4. Smíchání: nalij 2 do 1                                   | |",
        "___| |_____________________________________________________________| |__",
        "(__   _____________________________________________________________   __)",
        "   | |                                                             | |"};
    
        Cau_Hoi q1;
        q1.so_thu_tu = 1;
        q1.loai = 1;
        q1.cau_thuong ="Kolik ml chlornanu sodného: ";
        q1.cau_tra_loi_dung_so = 2;

        Cau_Hoi q2;
        q2.so_thu_tu =2;
        q2.loai =0;
        q2.cau_thuong ="0,8 g čeho máme smíchat s 0,1 g luminolu: ";
        q2.cau_tra_loi_dung_van_ban ={"hydroxid sodny" ,"hydroxid sodný" , "hydroxidsodny"};

        level.danh_sach_cau_hoi.push_back(q1);
        level.danh_sach_cau_hoi.push_back(q2);
        level.duong_dan_video =("video_reakce\\luminol.mp4");

        return level;

}
Cap_Do level3(){
    Cap_Do level;
    level.ten_cap_do =  "Level 3 - Howl of the Hellhound";
    level.cac_huong_Dan = {
        "___| |___________________________________________________________________| |__",
        "(__   ___________________________________________________________________   __)",
        "   | |                                                                   | |",
        "   | |              [ ✦ Level 3 - Howl of the Hellhound ✦ ]             | |",
        "   | |                                                                   | |",
        "   | |postup                                                             | |",
        "   | | 1. Bezpečnost: rukavice + brýle                                   | |",
        "   | | 2. Válec 1: nalníme 1-1,5litru plynu(N₂O nebo NO)                 | |",
        "   | | 3. Přijdáme ~2-3ml sirouhlíku (CS₂), zakryjem válec a protřepem.  | |",
        "   | | 4. Otevřem a zapalíme                                             | |",
        "___| |___________________________________________________________________| |__",
        "(__   ___________________________________________________________________   __)",
        "   | |                                                                   | |"};
    
        Cau_Hoi q1;
        q1.so_thu_tu = 1;
        q1.loai = 0;
        q1.cau_thuong ="Jaký plyn se v experimentu používá kromě NO nebo N₂O(napiš název plynu): ";
        q1.cau_tra_loi_dung_van_ban = {"sirouhlik","sirouhlík"};

        Cau_Hoi q2;
        q2.so_thu_tu =2;
        q2.loai =1;
        q2.cau_thuong ="Kolik sirouhlíku se přidává na 1 litr plynu(v ml): ";
        q2.cau_tra_loi_dung_so =2;

        level.danh_sach_cau_hoi.push_back(q1);
        level.danh_sach_cau_hoi.push_back(q2);
        level.duong_dan_video =("video_reakce\\barking_dog.mp4");

        return level;

}
Cap_Do level4(){
    Cap_Do level;
    level.ten_cap_do =  "Level 4 - Iron Rain";
    level.cac_huong_Dan = {
        "___| |___________________________________________________________________| |__",
        "(__   ___________________________________________________________________   __)",
        "   | |                                                                   | |",
        "   | |                     [ ✦ Level 4 - Iron Rain ✦ ]                  | |",
        "   | |                                                                   | |",
        "   | |postup                                                             | |",
        "   | | 1. Bezpečnost: rukavice + brýle                                   | |",
        "   | | 2. Smícháme v poměru 3(Hliníku[Al):8(Oxid železitý[Fe₂O₃)         | |",
        "   | | 3. Potřebujeme vysokou teplotu k aktivaci, proto do směsi prášku  | |",
        "   | |    zapíchneme hořčíkovou tyčinku a zapálíme ji.                   | |",
        "___| |___________________________________________________________________| |__",
        "(__   ___________________________________________________________________   __)",
        "   | |                                                                   | |"};
    
        Cau_Hoi q1;
        q1.so_thu_tu = 1;
        q1.loai = 0;
        q1.cau_thuong ="Jak se jinak říká hliníku: ";
        q1.cau_tra_loi_dung_van_ban = { "aluminium"};

        Cau_Hoi q2;
        q2.so_thu_tu =2;
        q2.loai =0;
        q2.cau_thuong ="V jakém minerálu se oxid železitý (Fe₂O₃) vyskytuje nejčastěji: ";
        q2.cau_tra_loi_dung_van_ban ={"hematit"};

        level.danh_sach_cau_hoi.push_back(q1);
        level.danh_sach_cau_hoi.push_back(q2);
        level.duong_dan_video =("video_reakce\\thermit.mp4");

        return level;

}
Cap_Do level5(){
    Cap_Do level;
    level.ten_cap_do =  "Level 5 - Abyssal Detonation";
    level.cac_huong_Dan = {
        " __| |__________________________________________________________________________| |__",
        "(__   __________________________________________________________________________   __)",
        "   | |                                                                          | |",
        "   | |                  [ ✦ Level 5 - Abyssal Detonation ✦ ]                   | |",
        "   | |                                                                          | |",
        "   | |postup                                                                    | |",
        "   | | 1. Bezpečnost: rukavice + brýle                                          | |",
        "   | | 2. Nastříkej dva plyny vodík 17:3 kyslík do jednoho balónku              | |",
        "   | | 3. Balónek pak pomocí hadičky vypusť do nádoby s mýdlovou vodou          | |",
        "   | |    Na hladině se vytvoří bubliny, vezmi zapalovač a tyto bubliny zapal   | |",
        " __| |__________________________________________________________________________| |__",
        "(__   __________________________________________________________________________   __)",
        "   | |                                                                          | |"};

    
        Cau_Hoi q1;
        q1.so_thu_tu = 1;
        q1.loai = 0;
        q1.cau_thuong ="Jak se nazývá látka vznikající reakcí vodíku a kyslíku?: ";
        q1.cau_tra_loi_dung_van_ban = { "voda"};

        Cau_Hoi q2;
        q2.so_thu_tu =2;
        q2.loai =0;
        q2.cau_thuong ="Jak se obecně označuje prudká reakce doprovázená uvolněním velkého množství energie?: ";
        q2.cau_tra_loi_dung_van_ban ={"exploze"};

        level.danh_sach_cau_hoi.push_back(q1);
        level.danh_sach_cau_hoi.push_back(q2);
        level.duong_dan_video =("video_reakce\\bubble.mp4");

        return level;

}

int Doan_so(const vector<int>& mat_ma, vector<int>& cua_nguoi_choi, int& so_lan_thu){
        Dat_Mau_Chu(13);
        cout << "── .✦" << (so_lan_thu+1) << " Pokus ✦. ──" << endl;
        Dat_Mau_Chu(7);
        for(int j =0;j<5;j++){
            int x;
            Dat_Mau_Chu(11);
            cout << "Na [" << j+1 << "] pozici dlí tvé první rozhodnutí: ";
            cin>>x;
            cua_nguoi_choi.push_back(x);
        }
        so_lan_thu++;
        cout<<endl;
        xoa_dong(6);
    
    Dat_Mau_Chu(3);
    for(auto x: cua_nguoi_choi){
        cout << "[" << x << "] ";
    }cout<<endl;
    Dat_Mau_Chu(7);

    int so_cau=0;
    for (int i = 0; i < 5; i++){
        if (mat_ma[i]==cua_nguoi_choi[i]){
            Dat_Mau_Chu(14);
            cout << "Stíny potvrdily tvou volbu. Číslo " << cua_nguoi_choi[i] 
                << " svůj pravý osud." << endl;
            Dat_Mau_Chu(7);
            so_cau++;
        }else {
            bool tim_cho = false;
            for (int j = 0; j < 5; j++) {
                if (mat_ma[j] == cua_nguoi_choi[i]) {
                    tim_cho = true;
                    break;
                }
            }
            if (tim_cho) {
                Dat_Mau_Chu(14);
                cout << "Stín tě mýlí: Číslo " << cua_nguoi_choi[i] 
                    << " je přítomno, leč bloudí na špatném místě." << endl;
                Dat_Mau_Chu(7);
                so_cau++;
            }
        }
    }
    Sleep(5000);

    return so_cau+(so_lan_thu*2);
}

int Vong_Doan_So_5_Sai(const vector<int>& mat_ma) {
    Dat_Mau_Chu(13);
    in_text("── ⋆⋅𖤓⋅⋆ ──", 190);
    in_text("Zadej své heslo a vyvolej stíny minulosti.", 170);
    in_text("── ⋆⋅𖤓⋅⋆ ──", 190);
    Dat_Mau_Chu(14);
    in_text("Předivo osudu ti darovalo 5 pokusů. Využij je moudře, nebo tě pohltí prázdnota", 170);
    Dat_Mau_Chu(7);
    
    vector<int> cua_nguoi_choi;
    int so_lan_choi = 0;
    
    do {
        Doan_so(mat_ma, cua_nguoi_choi, so_lan_choi);  // ✓ so_lan_choi được cập nhật
        
        if (equal(mat_ma.begin(), mat_ma.end(), cua_nguoi_choi.begin())) {
            xoa_dong(Doan_so(mat_ma,cua_nguoi_choi,so_lan_choi));
            Dat_Mau_Chu(10);
            in_text("Předivo stínů se rozestoupilo. Odhadli jste tajný klíč.", 170);
            Dat_Mau_Chu(7);
            return 0;
        }
        
        cua_nguoi_choi.clear();  // ✓ Xóa để nhập lại
    } while (so_lan_choi < 5);
    
    Dat_Mau_Chu(12);
    in_text("Pátý pokus byl tvůj poslední. Světlo naděje zhaslo – poklad ti nenáleží, patří nyní temnotě.", 170);
    Dat_Mau_Chu(7);
    return 1;
}
int Vong_Doan_So_3_Sai(const vector<int>& mat_ma) {
    Dat_Mau_Chu(13);
    in_text("── ⋆⋅𖤓⋅⋆ ──", 190);
    in_text("Zadej své heslo a vyvolej stíny minulosti.", 170);
    in_text("── ⋆⋅𖤓⋅⋆ ──", 190);
    Dat_Mau_Chu(14);
    in_text("Předivo osudu ti darovalo 3 pokusů. Využij je moudře, nebo tě pohltí prázdnota", 170);
    Dat_Mau_Chu(7);
    
    vector<int> cua_nguoi_choi;
    int so_lan_doan = 0;
    
    do {
        Doan_so(mat_ma, cua_nguoi_choi, so_lan_doan);
        
        if (equal(mat_ma.begin(), mat_ma.end(), cua_nguoi_choi.begin())) {
            Dat_Mau_Chu(10);
            in_text("Předivo stínů se rozestoupilo. Odhadli jste tajný klíč.", 170);
            Dat_Mau_Chu(7);
            return 0;
        }
        
        cua_nguoi_choi.clear();  // ✓ Xóa để nhập lại
    } while (so_lan_doan < 3);
    
    Dat_Mau_Chu(12);
    in_text("Třetí pokus byl tvůj poslední. Světlo naděje zhaslo – poklad ti nenáleží, patří nyní temnotě.", 170);
    Dat_Mau_Chu(7);
    return 1;
}
int Doan_So_Khong_Sai(const vector<int>& mat_ma) {
    Dat_Mau_Chu(13);
    in_text("── ⋆⋅𖤓⋅⋆ ──", 190);
    in_text("Zadej své heslo a vyvolej stíny minulosti.", 170);
    in_text("── ⋆⋅𖤓⋅⋆ ──", 190);
    Dat_Mau_Chu(7);
    
    vector<int> cua_nguoi_choi;
    int so_lan = 0;
    
    Doan_so(mat_ma, cua_nguoi_choi, so_lan);  // ✓ Tái sử dụng
    
    if (equal(mat_ma.begin(), mat_ma.end(), cua_nguoi_choi.begin())) {
        Dat_Mau_Chu(10);
        in_text("Předivo stínů se rozestoupilo. Odhadli jste tajný klíč.", 170);
        Dat_Mau_Chu(7);
        return 0;
    } else {
        Dat_Mau_Chu(12);
        in_text("Stíny ti odhalily všechna tajná čísla… ale tvé zaváhání udrželo poklad zapečetěný.", 180);
        Dat_Mau_Chu(7);
        return 1;
    }
}

void Hien_thi_closed_chest(){
    vector<string> treasure = {
        "        ███████████████████████████████████████████████████████████████████",
        "    ███████████████████████████████████▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██████",
        "  ▓▓▓▓▓▓░░░░░██████░░░░▒▒░░░░████████▓▓████▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░██",
        " ██▒▒▒▒░░░░░░░░░░░████░░░░░░░░░░██████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░██",
        "▓▓▒▒▒▒░░░░░░░░░░░░░░░██▓▓░░░░░░░░░░████████████████████████████████████████████░░░░░░░░▓▓",
        "▓▓▒▒▒▒░░░░░░░░░░░░░░░░░░░██▓▓▒▒░░░░░░░░██████████▓▓▓▓▓▓████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░██▓▓",
        "██▒▒▒▒░░░░░▒▒████░░░░░░░░░░░░██▒▒▒▒░░░░░░████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░░░░░██",
        "██▒▒▒▒░░░████▓▓████░░░░░░░░░░░░██▒▒░░░░░░░░████▓▓██▓▓████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒░░░░░░██",
        "░░▒▒░░░░█████▓▓▓▓▓▓██░░░░░░░░░░██▒▒▒▒░░░░░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒░░░░░░████",
        "██▒▒▒▒░░█████▓▓▓▓▓▓▓▓▓▓████░░░░░░░░██▒▒▒▒▒▒▒▒████▓▓▓▓██████▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒░░░░░░░░██",
        "██▒▒▒▒▒▒█████▓▓▓▓▓▓▓▓▓▓████░░░░░░░░██▒▒▒▒▒▒░░██████████▓▓████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████████████",
        "██████▓▓███████████████████▓▓██▓▓▓▓████████▓▓██████████████████████████████████████░░░░░░░░░░░░░░░░████",
        "██▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██▒▒▒▒░░░░░░░░░░░░░░░░░░██▒▒▒▒░░░░▒▒░░░░░░░░░░░░██▒▒▒▒░░░░░░░░░░░░██",
        "██▒▒░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░██▒▒▒▒▒▒░░▒▒░░░░░░░░░░░░██▒▒▒▒░░░░░░██████░░░░░░██▒▒░░░░░░░░░░░░████",
        "██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░██░░░░▒▒▒▒░░░░░░░░░░░░░░██▒▒▒▒░░░░██▓▓▓▓▓▓██░░░░██▒▒░░░░░░░░░░░░██",
        "█████████████████████████████████████████████████████████████▒▒▒▒░░░░██▓▓▓▓████░░░░██████████████████",
        "██▒▒▒▒▒▒███▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒░░▒▒▒▒░░██▒▒▒▒▒▒░░██████████▓▓██▒▒▒▒░░░░░░██▓▓██░░░░░░██████████░░░░░░██",
        "██▒▒▒▒▒▒███▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒▒▒░░░░████████▓▓▓▓██▒▒▒▒░░░░░░██▓▓██░░░░░░██████████░░░░░░██",
        "██▒▒▒▒░░█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒░░░░░░████████▓▓▓▓██▒▒▒▒░░░░░░██▓▓██░░░░░░██████▓▓██░░░░░░██",
        "██▒▒▒▒░░█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒░░░░░░██████▓▓▓▓▓▓██▒▒▒▒░░░░░░██████░░░░░░████▓▓▓▓██░░░░░░██",
        "██▒▒▒▒░░███▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒░░░░░░██████████▓▓██▒▒▒▒░░░░░░░░░░░░░░░░░░████▓▓▓▓██░░░░░░██",
        "██▒▒░░░░███████████████████░░░░░░░░░░██▒▒░░░░░░████████████████▒▒▒▒░░░░░░░░░░░░░░████████████░░░░░░██",
        "██▒▒░░░░█████▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒░░░░░░██████████████████▒▒▒▒▒▒░░░░░░░░████▓▓▓▓▓▓▓▓██░░░░░░██",
        "██▒▒░░░░█████▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒░░░░░░████▓▓▓▓▓▓▓▓████████░░▒▒░░░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░██",
        "██▒▒░░░░█████▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒░░░░░░████████████▓▓▓▓████▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░██",
        "██▒▒░░░░███▓▓██▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒░░░░░░████▓▓▓▓▓▓▓▓▓▓▓▓████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░██",
        "██▒▒░░░░███████▓▓▓▓▓▓▓▓▓▓██░░░░░░░░░░██▒▒░░░░░░██████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████████░░░░░░██",
        "██▒▒░░░░███████████████████░░░░░░░░░░██▒▒░░░░░░██████████████████████████████████████████████▒▒░░░░██",
        "██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░██▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒░░░░██",
        "██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░██",
        "██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████"};

    Dat_Mau_Chu(8);
    for(auto x: treasure){
        in_luat_choi(x,82,150);
    }Dat_Mau_Chu(7);

}
void Hien_thi_video_kho_bau(const char* ten_file){
    ifstream soubor(ten_file);
    string radek;
    vector<string> poklad;
    
    if (soubor.is_open()) {
        while (getline(soubor, radek)) {
            poklad.push_back(radek);
        }
        soubor.close();
    }
    int kho_bau_ngau_nhien = rand() % poklad.size();
    Dat_Mau_Chu(13);
    in_text("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
    Dat_Mau_Chu(8);
    in_text("Z hlubin se cosi probouzí...", 170);
    Sleep(1000);
    Dat_Mau_Chu(13);
    in_text("Temnota šeptá tvé jméno...", 170);
    Sleep(1000);
    Dat_Mau_Chu(14);
    in_text(poklad[kho_bau_ngau_nhien], 170);
    Dat_Mau_Chu(13);
    in_text("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
    Dat_Mau_Chu(7);
    Sleep(2000);

    string lenh = "start video_poklad\\video"+to_string(kho_bau_ngau_nhien+1)+".mp4";
    system(lenh.c_str());
}
void Hien_Thi_So_Bi_Mat(int so_level, int so_bi_mat) {
    Dat_Mau_Chu(13);
    in_text("── ⋆⋅𖤓⋅⋆ ──", 185);
    Sleep(500);
    
    Dat_Mau_Chu(14);
    in_text("Stíny odhalují tajemství...", 170);
    Sleep(1500);
    
    Dat_Mau_Chu(10);    
    in_text("  ✦"+to_string(so_level) +". Číslo: " + to_string(so_bi_mat) + " ✦  ", 170);
    Dat_Mau_Chu(7);
    Sleep(500);
    in_text("── ⋆⋅𖤓⋅⋆ ──", 185);
    Sleep(5000);
    xoa_dong(6);
}

void Hien_thi_open_chest(const char* ten_file){
    Dat_Mau_Chu(14);
    vector<string> chest = {
        "                   █████████████████████████████████████████████████████████████████████████████████              ",
        "         ░░░░░░░░▒▒▒▒▒██████████▓▓▓▓▓▓▓▓▓▓▓▓██████████████████████████████▒▒▒▒▒▒██████▒▒▒▒▒▒▒▒▒▒▒▒░░░░░        ",
        "         ████████░░░░░░█████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████▓▓████████████████░░░░░░██████░░░░░░░░░░░░███▓▓        ",
        "       ██░░░░░░░░██████▓▓▓▓▓██████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓░░░░░░▒▒██░░░░░░██████████▓▓░░░░░██      ",
        "       ██░░░░░░░░██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████░░░░░░▓▓██░░░░██▓▓▓▓▓▓▓▓██████░░░██      ",
        "   ████░░░░░░████▓▓▓▓▓▓██████▓▓███████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████░░░░░░░░██▓▓░░██████▓▓▓▓▓▓▓▓▓▓▓▓███▓▓░░████  ",
        "   ████░░░░░░████▓▓▓▓▓▓▓▓▓▓▓▓█████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████░░░░░░░░██▒▒░░████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▓▓░░██▓▓  ",
        "   █████████████████████████████████████████████████████████████████████████▒▒░░██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "       ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓██████▓▓████▓▓▓▓▓▓▓▓███████░░░░██",
        "       ██░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██████▓▓██▓▓▓▓▓▓▓▓▓▓███████░░░░██",
        "         ████▒▒░░███████████████████████████████████████████████████████████▒▒░░██████▓▓▓▓██████▓▓▓▓▓▓▓██░░░░██",
        "             ████░░▓▓███████████████████████████████████████████████████████████░░▒▒██████▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "             ░░░░▒▒▒▒▒▒████▓▓▒▒▒▒▒▒▒▒▒▒▒▒███████████████████████▒▒██████████████▒▒▒▒▒▒████▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "                 ██▒▒░░██▓▓▒▒░░  ░░░░░░░░▒▒▓▓▒▒▒▒█████████████▓▓▓▓▒▒████████████████▒▒████████▓▓▓▓██▓▓▓██░░░░██",
        "                   ▒▒░░░░▒▒██████████████████░░  ░░░░░░░░░▒██▓▒▒▓▓░░▒▒████████████████░░▒▒████████▓▓▓▓▓██░░░░██",
        "                   ▒▒▒▒██▓▓░░░░░░░░░░░░░░░░░░██▒▒░░░░▒▒░░░░░▓▓██████▓▓▓▓██░░░░░░░░░░██████▒▒░░██████▓▓▓██░░░░██",
        "           ░░░░░░▒▒▒▒▒▒██▓▓░░░░████████░░░░░░██░░░░░░░░░░░░░▒▒▒░░░░░░░░░░░░░░░░░  ░░▒▒████████░░▒▒███████░░░░██",
        "       ░░░░░░▒▒▒▒▒▒▓▓▓▓████░░▓▓████████▓▓░░░░██░░░░▒▒▒▒░░░░░▒▒▒▒░░░▒▒▒▒▒▒▒░░░░▒▒▒▒░░░░▒▒▒▒▒▒██▓▓▒▒▒▒█████░░░░██",
        "   ░░░░░░░░░░░░░░▒▒▒▒░░██▓▓░░▓▓██████████░░░░██░░░░░░▒▒░░ ▒▒▒▒░░  ░░▒▒▒░░░░░░░░░░░░░  ░░  ░░▒▒████▒▒█████░░░░██",
        "█████████████████████████▓▓░░░░▒▒████▓▓░░░░░░██████████▒▒▒▒████████████████████████████████████████████████████",
        "███▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▓▓░░░░░░██████░░░░░░██▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒████▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██",
        "███░░░░██░░░░░░░░░░░░░░██▓▓░░░░░░██████░░░░░░██░░░░░░░▒▒▒▒▒░░░████░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██",
        "█▓▓░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒████░░░░░░████▓▓░░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒░░░████░░░░████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░░░██",
        "█▓▓░░░░██████████████████▓▓░░░░░░████▓▓░░░░░░████████▒▒▒▒▒▒▒▒░████░░░░███████████████████████████████████░░░░██",
        "███░░░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓░░░░░░░░░░░░░░░░░░██▓▓▓▓▓▓▒▒▒▒▒▒░░░████░░░░██████▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "█▓▓░░░░██▓▓▓▓▓▓▓▓▓▓▓▓██████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████▓▓░░░████░░░░██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓█████░░░░██",
        "███░░░░██████████████████████████████████████████████████▓▓░░░████░░░░███████████████████████████████████░░░░██",
        "█▓▓░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██▓▓░░░████░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██",
        "█▓▓░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██",
        "█▓▓████████████████████████████████████████████████████████████████████████████████████████████████████████████"};


    for(auto x: chest){
        in_luat_choi(x,82,150);
    }
    Dat_Mau_Chu(7);
    Hien_thi_video_kho_bau(ten_file);
}
void in_mat_khau(vector <int>mat_ma){
    cout<<"Tajné heslo bylo: ";
    for(auto x: mat_ma){
        cout<<"["<<x<<"] ";
    }cout<<endl;
}
void Hra(Player *player,const char* ten_file, const vector<int>mat_ma){
    int tong_so_loi=0;

    vector <Cap_Do> danh_sach_level = {level1(),level2(),level3(),level4(),level5()};

    for (size_t i=0; i<danh_sach_level.size();i++){//khong dung size_t thi khong the dung duoc danh_sach_level.size()
        int ket_qua = thuc_hien_cap_do(player,danh_sach_level[i],tong_so_loi);
        if (ket_qua==0){
            cout<<endl;
            Dat_Mau_Chu(13);
            in_text("Stíny tentokrát ustoupily tvé vůli. Z hlubin se vynořilo jedno zapomenuté číslo.", 170);
            Sleep(THOIGIAN_DELAY_TRA_LOI);
            Dat_Mau_Chu(7);
            cout<<endl;
            Hien_Thi_So_Bi_Mat(i+1,mat_ma[i]);
        }else if(ket_qua==2){
            Dat_Mau_Chu(12);
            in_text("Tento level jsi nakonec překonal, ale kvůli chybě ti stíny číslo neodhalí.", 170);
            Dat_Mau_Chu(7);
            Sleep(3000);
            xoa_dong(1);
        }
        
    }
    Hien_thi_closed_chest();
    Sleep(THOIGIAN_DELAY_TRA_LOI);
    if (tong_so_loi==5){
        if (Vong_Doan_So_5_Sai(mat_ma)==0){
            Hien_thi_open_chest(ten_file);
        }else {
            Dat_Mau_Chu(12);
            in_text("Tvá ruka se zachvěla. Rozhodl jsi se nečelit osudu – poklad si počká na někoho odvážnějšího", 170);
            in_mat_khau(mat_ma);
            Dat_Mau_Chu(7);
            exit(0);
        } 
    }else if(tong_so_loi>0 && tong_so_loi<5){
        if (Vong_Doan_So_3_Sai(mat_ma)==0){
            Hien_thi_open_chest(ten_file);
        }else {
            Dat_Mau_Chu(12);
            in_text("Tvá ruka se zachvěla. Rozhodl jsi se nečelit osudu – poklad si počká na někoho odvážnějšího", 170);
            in_mat_khau(mat_ma);
            Dat_Mau_Chu(7);
            exit(0);
        } 
    }else if (tong_so_loi==0){
        if (Doan_So_Khong_Sai(mat_ma)==0){
        Hien_thi_open_chest(ten_file);
        }else {
            Dat_Mau_Chu(12);
            in_text("Tvá ruka se zachvěla. Rozhodl jsi se nečelit osudu – poklad si počká na někoho odvážnějšího", 170);
            in_mat_khau(mat_ma);
            Dat_Mau_Chu(7);
            exit(0);
        } 
        
    }
    
    
}
int main (){
    srand(time(0));
    system("chcp 65001"); // UTF-8 podpora
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    in_tua_de();

    vector<int>mat_ma;
    mat_ma_kho_bau(mat_ma);
    Player hrac;
    tao_player(&hrac);
    Hra(&hrac,"poklad.txt",mat_ma);
    //Vong_Doan_So_3_Sai(mat_ma);


    

    return 0;

}