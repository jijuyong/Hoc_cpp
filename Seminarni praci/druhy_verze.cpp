#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctype.h>

using namespace std;

typedef struct
{
    char name[50];
} Character;

void xoa_bang(int size)
{
    string clearSequence = "";
    for (int i = 0; i < size; i++)
    {
        clearSequence += "\x1B[A\x1B[2K"; // Build string
    }
    cout << clearSequence; // Single output
}

void mat_ma_cua_kho_bau(vector<int> &mat_khau)
{
    for (int i = 0; i < 5; i++)
    {
        int x = rand() % 10;
        mat_khau.push_back(x);
    }

    // for (auto x : mat_khau){
    //     cout << "[" << x << "] ";
    // }
    // cout << endl;

    // cout << endl;
}

void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int tra_loi_sai(Character *player)
{
    system("start video_reakce\\explosion.mp4");
    SetColor(12);
    cout << player->name << ", chceš znovu zkusit? (ano/ne): ";
    string odpoved;
    getline(cin, odpoved);
    SetColor(7);
    if (odpoved == "ano")
    {
        xoa_bang(1);
        return 1;
    }
    else
    {
        cout << "Díky za hraní! 👋🏻" << endl;
        exit(0);
    }
}

void int_ra_giua_tua_de(string text, int displayWidth, int windowWidth)
{
    int spaces = (windowWidth - displayWidth) / 2;
    if (spaces > 0)
    {
        for (int i = 0; i < spaces; i++)
            cout << " ";
    }
    cout << text << endl;
}

void in_ra_giua(string text, int chieu_rong)
{
    int in = (chieu_rong - text.length()) / 2;
    if (in > 0)
    {
        cout << string(in, ' ');
    }
    cout << text << endl;
}

void in_tua_de()
{

    SetColor(10);
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

    for (const auto &line : tua_de_game)
    {
        int_ra_giua_tua_de(line, 82, 170);
    }
    in_ra_giua("Stiskni ENTER a začni hru...", 170);
    cin.get(); // čeká na Enter
    xoa_bang(2);
    cout << endl;
    Sleep(2000);
    SetColor(7);

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

    for (const auto &dong : luat_choi)
    {
        int_ra_giua_tua_de(dong, 55, 150);
    }
    in_ra_giua("Pokud jsi už četl pravidla, stiskni ENTER pro pokračování...", 175);
    cin.get(); // čeká na Enter
    xoa_bang(luat_choi.size() + 2);
    cout << endl;
    Sleep(2000);
}

void tao_player(Character *player)
{
    SetColor(13);
    char ten[50];
    cout << "Zadej jméno svého charakteru: ";
    cin >> ten;
    strcpy(player->name, ten);
    Sleep(2000);
    xoa_bang(1);
    in_ra_giua("∘₊✧─────✧₊∘", 192);
    in_ra_giua(player->name, 170);
    in_ra_giua("∘₊✧─────✧₊∘", 192);
    SetColor(7);
    Sleep(2000);
}

void danh_sach_reakce(const char *file_name)
{

    ifstream soubor(file_name);
    string radek;
    vector<string> rce;

    if (soubor.is_open())
    {
        while (getline(soubor, radek))
        {
            rce.push_back(radek);
        }
        soubor.close();
    }
    for (auto x : rce)
    {
        cout << x << endl;
    }
}

int level1(Character *player)
{
    int lan_tra_loi_sai=0;
    int* ptr =&lan_tra_loi_sai;
    bool hoan_thanh = false;
    SetColor(14);
    vector<string> luat_choi = {
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

    for (const auto &dong : luat_choi)
    {
        int_ra_giua_tua_de(dong, 55, 150);
    }
    in_ra_giua("⏱️MÁŠ 15 SEKUND NA ZAPAMATOVÁNÍ ⏱️", 150);
    SetColor(7);
    Sleep(2000); // doi 15s
    xoa_bang(luat_choi.size() + 1);
    Sleep(2000);
    while (!hoan_thanh)
    {
        SetColor(11);
        cout << "── .✦Otázka 1✦. ──" << endl;
        SetColor(7);
        string cauhoi1;
        cout << "Zadejte název H₂O₂: ";
        getline(cin >> ws, cauhoi1); // vyčisti vstup od Enteru a mezer
        for (int i = 0; i < cauhoi1.size(); i++)
        {
            cauhoi1[i] = tolower(cauhoi1[i]);
        }
        Sleep(2000);
        xoa_bang(2);
        if (cauhoi1 == "peroxid vodiku" || cauhoi1 == "peroxid vodíku" || cauhoi1 == "peroxidvodiku")
        {
            SetColor(10);
            cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
            SetColor(7);
            Sleep(2000);
            xoa_bang(1);
            hoan_thanh =true;
        }
        else
        {
            if (tra_loi_sai(player) == 1)
            {
                lan_tra_loi_sai++;
                cout << "lan tra loi sai: " << lan_tra_loi_sai << endl;
                level1(player);
                
            }
        }
        cout << "lan tra loi sai: " << lan_tra_loi_sai << endl;
    }
    // cau tra loi2
    SetColor(11);
    cout << "── .✦Otázka 2✦. ──" << endl;
    SetColor(7);
    int cauhoi2;
    cout << "Kolik gramů droždí (katalyzátoru) použiješ(gram)?: ";
    cin >> cauhoi2;
    cin.ignore();
    Sleep(2000);
    xoa_bang(2);
    if (cauhoi2 == 15)
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        cout << "chcete vidět reakce? (ano/ne): ";
        string choice;
        cin >> choice;
        xoa_bang(2);
        if (choice == "ano")
        {
            system("start video_reakce\\elephant.mp4");
            cout << "Až zavřeš video, stiskni ENTER...";
            cin.ignore();
            cin.get();
            xoa_bang(1);
        }
    }
    else if (cauhoi2 != 15)
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            cout << "lan tra loi sai: " << lan_tra_loi_sai << endl;
            level1(player);
        }
    }
    cout << "lan tra loi sai: " << *ptr << endl;

    return lan_tra_loi_sai > 0 ? 1 : 0;
}


int level2(Character *player)
{
    int lan_tra_loi_sai = 0;
    SetColor(14);
    vector<string> luat_choi = {
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

    for (const auto &dong : luat_choi)
    {
        int_ra_giua_tua_de(dong, 55, 150);
    }
    in_ra_giua("⏱️MÁŠ 15 SEKUND NA ZAPAMATOVÁNÍ ⏱️", 150);
    SetColor(7);
    Sleep(2000); // doi 15s
    xoa_bang(luat_choi.size() + 1);
    Sleep(2000);
    SetColor(11);
    cout << "── .✦Otázka 1✦. ──" << endl;
    SetColor(7);
    int cauhoi1;
    cout << "Kolik ml chlornanu sodného: ";
    cin >> cauhoi1;
    cin.ignore();
    Sleep(2000);
    xoa_bang(2);
    if (cauhoi1 == 2)
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        Sleep(2000);
        xoa_bang(1);
    }
    else
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            return level2(player);
        }
    }

    // cau tra loi2
    SetColor(11);
    cout << "── .✦Otázka 2✦. ──" << endl;
    SetColor(7);
    string cauhoi2;
    cout << "0,8 g čeho máme smíchat s 0,1 g luminolu: ";
    getline(cin >> ws, cauhoi2);
    Sleep(2000);
    xoa_bang(2);
    for (int i = 0; i < cauhoi2.size(); i++)
    {
        cauhoi2[i] = tolower(cauhoi2[i]);
    }
    if (cauhoi2 == "hydroxid sodny" || cauhoi2 == "hydroxid sodný" || cauhoi2 == "hydroxidsodny")
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        cout << "chcete vidět reakce? (ano/ne): ";
        string choice;
        cin >> choice;
        xoa_bang(2);
        if (choice == "ano")
        {
            system("start video_reakce\\luminol.mp4");
            cout << "Až zavřeš video, stiskni ENTER...";
            cin.ignore();
            cin.get();
            xoa_bang(1);
        }
    }
    else
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            return level2(player);
        }
    }

    return lan_tra_loi_sai > 0 ? 1 : 0;
}

int level3(Character *player)
{
    int lan_tra_loi_sai = 0;
    SetColor(14);
    vector<string> luat_choi = {
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

    for (const auto &dong : luat_choi)
    {
        int_ra_giua_tua_de(dong, 55, 150);
    }
    in_ra_giua("⏱️MÁŠ 15 SEKUND NA ZAPAMATOVÁNÍ ⏱️", 150);
    SetColor(7);
    Sleep(2000); // doi 15s
    xoa_bang(luat_choi.size() + 1);
    Sleep(2000);
    SetColor(11);
    cout << "── .✦Otázka 1✦. ──" << endl;
    SetColor(7);
    string cauhoi1;
    cout << "Jaký plyn se v experimentu používá kromě NO nebo N₂O(napiš název plynu):  ";
    getline(cin >> ws, cauhoi1); // vyčisti vstup od Enteru a mezer
    for (int i = 0; i < cauhoi1.size(); i++)
    {
        cauhoi1[i] = tolower(cauhoi1[i]);
    }
    Sleep(2000);
    xoa_bang(2);
    if (cauhoi1 == "sirouhlik" || cauhoi1 == "sirouhlík")
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        Sleep(2000);
        xoa_bang(1);
    }
    else
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            return level3(player);
        }
    }

    // cau tra loi2
    SetColor(11);
    cout << "── .✦Otázka 2✦. ──" << endl;
    SetColor(7);
    int cauhoi2;
    cout << "Kolik sirouhlíku se přidává na 1 litr plynu(v ml):  ";
    cin >> cauhoi2;
    cin.ignore();
    Sleep(2000);
    xoa_bang(2);
    if (cauhoi2 == 2)
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        cout << "chcete vidět reakce? (ano/ne): ";
        string choice;
        cin >> choice;
        xoa_bang(2);
        if (choice == "ano")
        {
            system("start video_reakce\\barking_dog.mp4");
            cout << "Až zavřeš video, stiskni ENTER...";
            cin.ignore();
            cin.get();
            xoa_bang(1);
        }
    }
    else
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            return level3(player);
        }
    }

    return lan_tra_loi_sai > 0 ? 1 : 0;
}

int level4(Character *player)
{
    int lan_tra_loi_sai = 0;
    SetColor(14);
    vector<string> luat_choi = {
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

    for (const auto &dong : luat_choi)
    {
        int_ra_giua_tua_de(dong, 55, 150);
    }
    in_ra_giua("⏱️MÁŠ 15 SEKUND NA ZAPAMATOVÁNÍ ⏱️", 150);
    SetColor(7);
    Sleep(2000); // doi 15s
    xoa_bang(luat_choi.size() + 1);
    Sleep(2000);
    SetColor(11);
    cout << "── .✦Otázka 1✦. ──" << endl;
    SetColor(7);
    string cauhoi1;
    cout << "Jak se jinak říká hliníku: ";
    getline(cin >> ws, cauhoi1); // vyčisti vstup od Enteru a mezer
    for (int i = 0; i < cauhoi1.size(); i++)
    {
        cauhoi1[i] = tolower(cauhoi1[i]);
    }
    Sleep(2000);
    xoa_bang(2);
    if (cauhoi1 == "aluminium")
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        Sleep(2000);
        xoa_bang(1);
    }
    else
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            return level4(player);
        }
    }

    // cau tra loi2
    SetColor(11);
    cout << "── .✦Otázka 2✦. ──" << endl;
    SetColor(7);
    string cauhoi2;
    cout << "V jakém minerálu se oxid železitý (Fe₂O₃) vyskytuje nejčastěji: ";
    getline(cin >> ws, cauhoi2);
    for (int i = 0; i < cauhoi2.size(); i++)
    {
        cauhoi2[i] = tolower(cauhoi2[i]);
    }
    Sleep(2000);
    xoa_bang(2);
    if (cauhoi2 == "hematit")
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        cout << "chcete vidět reakce? (ano/ne): ";
        string choice;
        cin >> choice;
        xoa_bang(2);
        if (choice == "ano")
        {
            system("start video_reakce\\thermit.mp4");
            cout << "Až zavřeš video, stiskni ENTER...";
            cin.ignore();
            cin.get();
            xoa_bang(1);
        }
    }
    else
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            return level4(player);
        }
    }

    return lan_tra_loi_sai > 0 ? 1 : 0;
}

int level5(Character *player)
{
    int lan_tra_loi_sai = 0;
    SetColor(14);
    vector<string> luat_choi = {
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

    for (const auto &dong : luat_choi)
    {
        int_ra_giua_tua_de(dong, 55, 150);
    }
    in_ra_giua("⏱️MÁŠ 15 SEKUND NA ZAPAMATOVÁNÍ ⏱️", 150);
    SetColor(7);
    Sleep(2000); // doi 15s
    xoa_bang(luat_choi.size() + 1);
    Sleep(2000);
    SetColor(11);
    cout << "── .✦Otázka 1✦. ──" << endl;
    SetColor(7);
    string cauhoi1;
    cout << "Jak se nazývá látka vznikající reakcí vodíku a kyslíku?: ";
    getline(cin >> ws, cauhoi1); // vyčisti vstup od Enteru a mezer
    for (int i = 0; i < cauhoi1.size(); i++)
    {
        cauhoi1[i] = tolower(cauhoi1[i]);
    }
    Sleep(2000);
    xoa_bang(2);
    if (cauhoi1 == "voda")
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        Sleep(2000);
        xoa_bang(1);
    }
    else
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            return level5(player);
        }
    }

    // cau tra loi2
    SetColor(11);
    cout << "── .✦Otázka 2✦. ──" << endl;
    SetColor(7);
    string cauhoi2;
    cout << "Jak se obecně označuje prudká reakce doprovázená uvolněním velkého množství energie?: ";
    getline(cin >> ws, cauhoi2);
    for (int i = 0; i < cauhoi2.size(); i++)
    {
        cauhoi2[i] = tolower(cauhoi2[i]);
    }
    Sleep(2000);
    xoa_bang(2);
    if (cauhoi2 == "exploze")
    {
        SetColor(10);
        cout << "(👍🏻ᴗ _ᴗ)👍🏻,Správně!" << endl;
        SetColor(7);
        cout << "chcete vidět reakce? (ano/ne): ";
        string choice;
        cin >> choice;
        xoa_bang(2);
        if (choice == "ano")
        {
            system("start video_reakce\\bubble.mp4");
            cout << "Až zavřeš video, stiskni ENTER...";
            cin.ignore();
            cin.get();
            xoa_bang(1);
        }
    }
    else
    {
        if (tra_loi_sai(player) == 1)
        {
            lan_tra_loi_sai++;
            return level5(player);
        }
    }

    return lan_tra_loi_sai > 0 ? 1 : 0;
}

void closed_chest()
{
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

    for (auto x : treasure)
    {
        int_ra_giua_tua_de(x, 82, 150);
    }
}

void doan_so(vector<int> mat_ma, vector<int> cua_nguoi_choi, int so_lan_thu)
{
    for (int i = 0; i < 5; i++)
    {
        SetColor(13);
        cout << "── .✦" << i + 1 << "Pokus✦. ──" << endl;
        SetColor(7);
        int x;
        SetColor(11);
        cout << "Na [" << i << "] pozici dlí tvé první rozhodnutí: ";
        SetColor(7);
        cin >> x;
        cua_nguoi_choi.push_back(x);
        so_lan_thu++;
    }
    xoa_bang(5);
    for (auto x : cua_nguoi_choi)
    {
        cout << "[" << x << "] ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        if (mat_ma[i] == cua_nguoi_choi[i])
        {
            SetColor(10);
            cout << "Stíny potvrdily tvou volbu. Číslo " << cua_nguoi_choi[i] << " svůj pravý osud." << endl;
            SetColor(7);
        }
        else
        {
            bool tim_cho = false;
            for (int j = 0; j < 5; j++)
            {
                if (mat_ma[j] == cua_nguoi_choi[i])
                {
                    tim_cho = true;
                    break;
                }
            }
            if (tim_cho)
            {
                SetColor(14);
                cout << "Stín tě mýlí: Číslo " << cua_nguoi_choi[i] << " je přítomno, leč bloudí na špatném místě." << endl;
                SetColor(7);
            }
        }
    }
}

int loop_doan_so_5mistake(vector<int> &mat_ma)
{
    SetColor(13);
    in_ra_giua("── ⋆⋅𖤓⋅⋆ ──", 190);
    in_ra_giua("Zadej své heslo a vyvolej stíny minulosti.", 170);
    in_ra_giua("── ⋆⋅𖤓⋅⋆ ──", 190);
    SetColor(14);
    in_ra_giua("Předivo osudu ti darovalo 5 pokusů. Využij je moudře, nebo tě pohltí prázdnota", 150);
    SetColor(7);
    vector<int> cua_nguoi_choi;
    int so_lan_choi = 0;

    do
    {
        doan_so(mat_ma, cua_nguoi_choi, so_lan_choi);
        if (equal(mat_ma.begin(), mat_ma.end(), cua_nguoi_choi.begin()))
        {
            SetColor(10);
            in_ra_giua("Předivo stínů se rozestoupilo. Odhadli jste tajný klíč.", 150);
            SetColor(7);
            return 0;
        }
    } while (so_lan_choi < 5);
    SetColor(12);
    in_ra_giua("Pátý pokus byl tvůj poslední. Světlo naděje zhaslo – poklad ti nenáleží, patří nyní temnotě.", 150);
    SetColor(7);
    return 1;
}

int loop_doan_so_it_hon_5mistake(vector<int> &mat_ma)
{
    SetColor(13);
    in_ra_giua("── ⋆⋅𖤓⋅⋆ ──", 190);
    in_ra_giua("Zadej své heslo a vyvolej stíny minulosti.", 170);
    in_ra_giua("── ⋆⋅𖤓⋅⋆ ──", 190);
    SetColor(14);
    in_ra_giua("Předivo osudu ti darovalo 3 pokusů. Využij je moudře, nebo tě pohltí prázdnota", 150);
    SetColor(7);
    int so_lan_doan = 0;
    vector<int> cua_nguoi_choi;
    do
    {
        doan_so(mat_ma, cua_nguoi_choi, so_lan_doan);
        if (equal(mat_ma.begin(), mat_ma.end(), cua_nguoi_choi.begin()))
        {
            SetColor(10);
            in_ra_giua("Předivo stínů se rozestoupilo. Odhadli jste tajný klíč.", 150);
            SetColor(7);
            return 0;
        }
    } while (so_lan_doan < 3);
    SetColor(12);
    in_ra_giua("Třetí pokus byl tvůj poslední. Světlo naděje zhaslo – poklad ti nenáleží, patří nyní temnotě.", 150);
    SetColor(7);
    return 1;
}

int doan_so_zeromistake(vector<int> mat_ma)
{
    SetColor(13);
    in_ra_giua("── ⋆⋅𖤓⋅⋆ ──", 190);
    in_ra_giua("Zadej své heslo a vyvolej stíny minulosti.", 170);
    in_ra_giua("── ⋆⋅𖤓⋅⋆ ──", 190);
    vector<int> cua_nguoi_choi;
    for (int i = 0; i < 5; i++)
    {
        int x;
        SetColor(11);
        cout << "Na [" << i << "] pozici dlí tvé první rozhodnutí: ";
        SetColor(7);
        cin >> x;
        cua_nguoi_choi.push_back(x);
    }
    xoa_bang(5);
    for (auto x : cua_nguoi_choi)
    {
        cout << "[" << x << "] ";
    }
    cout << endl;

    if (equal(mat_ma.begin(), mat_ma.end(), cua_nguoi_choi.begin()))
    {
        SetColor(10);
        in_ra_giua("Předivo stínů se rozestoupilo. Odhadli jste tajný klíč.", 150);
        SetColor(7);
        return 0;
    }
    else
    {
        SetColor(12);
        in_ra_giua("Stíny ti odhalily všechna tajná čísla… ale tvé zaváhání udrželo poklad zapečetěný.", 180);
        SetColor(7);
        return 1;
    }
}

void in_video_kho_bau(const char *ten_file)
{
    int kho_bau_ngau_nhien = rand() % 10;

    ifstream soubor(ten_file);
    string radek;
    vector<string> poklad;

    if (soubor.is_open())
    {
        while (getline(soubor, radek))
        {
            poklad.push_back(radek);
        }
        soubor.close();
    }
    switch (kho_bau_ngau_nhien)
    {
    case 0:
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(8);
        in_ra_giua("Z hlubin se cosi probouzí...", 170);
        Sleep(1000);
        SetColor(13);
        in_ra_giua("Temnota šeptá tvé jméno...", 170);
        Sleep(1000);
        SetColor(14);
        in_ra_giua(poklad[0], 170);
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(7);
        Sleep(2000);
        system("start video_poklad\\video1.mp4 ");
        break;
    case 1:
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(8);
        in_ra_giua("Z hlubin se cosi probouzí...", 170);
        Sleep(1000);
        SetColor(13);
        in_ra_giua("Temnota šeptá tvé jméno...", 170);
        Sleep(1000);
        SetColor(14);
        in_ra_giua(poklad[1], 170);
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(7);
        Sleep(2000);
        system("start video_poklad\\video2.mp4 ");
        break;
    case 2:
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(8);
        in_ra_giua("Z hlubin se cosi probouzí...", 170);
        Sleep(1000);
        SetColor(13);
        in_ra_giua("Temnota šeptá tvé jméno...", 170);
        Sleep(1000);
        SetColor(14);
        in_ra_giua(poklad[2], 170);
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(7);
        Sleep(2000);
        system("start video_poklad\\video3.mp4 ");
        break;
    case 3:
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(8);
        in_ra_giua("Z hlubin se cosi probouzí...", 170);
        Sleep(1000);
        SetColor(13);
        in_ra_giua("Temnota šeptá tvé jméno...", 170);
        Sleep(1000);
        SetColor(14);
        in_ra_giua(poklad[3], 170);
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(7);
        Sleep(2000);
        system("start video_poklad\\video4.mp4 ");
        break;
    case 4:
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(8);
        in_ra_giua("Z hlubin se cosi probouzí...", 170);
        Sleep(1000);
        SetColor(13);
        in_ra_giua("Temnota šeptá tvé jméno...", 170);
        Sleep(1000);
        SetColor(14);
        in_ra_giua(poklad[4], 170);
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(7);
        Sleep(2000);
        system("start video_poklad\\video5.mp4 ");
        break;
    case 5:
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(8);
        in_ra_giua("Z hlubin se cosi probouzí...", 170);
        Sleep(1000);
        SetColor(13);
        in_ra_giua("Temnota šeptá tvé jméno...", 170);
        Sleep(1000);
        SetColor(14);
        in_ra_giua(poklad[5], 170);
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(7);
        Sleep(2000);
        system("start video_poklad\\video6.mp4 ");
        break;
    case 6:
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(8);
        in_ra_giua("Z hlubin se cosi probouzí...", 170);
        Sleep(1000);
        SetColor(13);
        in_ra_giua("Temnota šeptá tvé jméno...", 170);
        Sleep(1000);
        SetColor(14);
        in_ra_giua(poklad[6], 170);
        SetColor(13);
        in_ra_giua("✦•┈๑⋅⋯ ⋯⋅๑┈·✦", 190);
        SetColor(7);
        Sleep(2000);
        system("start video_poklad\\video7.mp4 ");
        break;
    }
}

void vyhra(const char *ten_file)
{
    SetColor(14);
    vector<string> chest = {
        "                                      ████████████████████████████████████████████████████████████████████████████████████████              ",
        "                              ░░░░░░░░▒▒▒▒▒▒████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████████████████████▒▒▒▒▒▒██████▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░        ",
        "                              ████████░░░░░░████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████▓▓████████████████░░░░░░██████░░░░░░░░░░░░████▓▓        ",
        "                            ██░░░░░░░░██████▓▓▓▓▓▓▓▓██████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓░░░░░░▒▒██░░░░░░██████████▓▓░░░░░░██      ",
        "                            ██░░░░░░░░████▓▓▓▓▓▓▓▓▓▓██████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓░░░░░░▒▒██░░░░░░██████████▓▓░░░░░░██      ",
        "                            ██░░░░░░░░██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████░░░░░░▓▓██░░░░██▓▓▓▓▓▓▓▓██████░░░░██      ",
        "                        ████░░░░░░████▓▓▓▓▓▓████████▓▓▓▓██████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████░░░░░░░░██▓▓░░██████▓▓▓▓▓▓▓▓▓▓▓▓████▓▓░░████  ",
        "                        ████░░░░░░████▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████░░░░░░░░██▒▒░░████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓░░██▓▓  ",
        "                        ████████████████████████████████████████████████████████████████████████████████▒▒░░██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "                            ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓██████▓▓████▓▓▓▓▓▓▓▓████████░░░░██",
        "                            ██░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██████▓▓██▓▓▓▓▓▓▓▓▓▓████████░░░░██",
        "                              ████▒▒░░██████████████████████████████████████████████████████████████████▒▒░░██████▓▓▓▓██████▓▓▓▓▓▓▓▓██░░░░██",
        "                                  ████░░▓▓██████████████████████████████████████████████████████████████████░░▒▒██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "                                  ░░░░▒▒▒▒▒▒████▓▓▒▒▒▒▒▒▒▒▒▒▒▒██████████████████████████████▒▒██████████████▒▒▒▒▒▒████▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "                                      ██▒▒░░██▓▓▒▒░░  ░░░░░░░░▒▒▓▓▒▒▒▒████████████████████▓▓▓▓▒▒████████████████▒▒████████▓▓▓▓██▓▓▓▓██░░░░██",
        "                                        ▒▒░░░░▒▒██████████████████░░  ░░░░░░░░░░░░▒▒████▓▓▒▒▓▓░░▒▒████████████████░░▒▒████████▓▓▓▓▓▓██░░░░██",
        "                                        ░░▓▓██▓▓░░▒▒░░░░░░▒▒▒▒▒▒▒▒▓▓░░░░▒▒▒▒░░░░░░░░░░░░▓▓░░▒▒▒▒▒▒▓▓▓▓░░▒▒████████▓▓▒▒▒▒▒▒██████▓▓▓▓██░░░░██",
        "                                        ▒▒▒▒██▓▓░░░░░░░░░░░░░░░░░░██▒▒░░░░▒▒░░░░      ░░▓▓██████▓▓▓▓██░░░░░░░░░░██████▒▒░░██████▓▓▓▓██░░░░██",
        "                                ░░░░░░▒▒▒▒▒▒██▓▓░░░░████████░░░░░░██░░░░░░░░░░░░░░░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░  ░░▒▒████████░░▒▒████████░░░░██",
        "                            ░░░░░░▒▒▒▒▒▒▓▓▓▓████░░▓▓████████▓▓░░░░██░░░░▒▒▒▒░░░░░░░░▒▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒░░░░▒▒▒▒▒▒██▓▓▒▒▒▒██████░░░░██",
        "                        ░░░░░░░░░░░░░░▒▒▒▒░░██▓▓░░▓▓██████████░░░░██░░░░░░▒▒░░░░  ▒▒▒▒░░  ░░▒▒▒▒░░░░░░░░░░░░░░░░  ░░  ░░▒▒████▒▒██████░░░░██",
        "                  ████████████████████████████▓▓░░░░▒▒████▓▓░░░░░░██████████████▒▒▒▒▒▒██████████████████████████████████████████████████████",
        "                  ████▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▓▓░░░░░░██████░░░░░░██▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██",
        "                  ████░░░░░░██░░░░░░░░░░░░░░██▓▓░░░░░░██████░░░░░░██░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░████░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██",
        "                  ██▓▓░░░░░░██░░░░░░░░░░░░░░████░░░░░░████▓▓░░░░░░██░░░░░░░░▓▓▒▒▓▓▒▒░░░░░░████░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██",
        "                  ██▓▓░░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒████░░░░░░████▓▓░░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░████░░░░████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░░░██",
        "                  ██▓▓░░░░░░██████████████████▓▓░░░░░░████▓▓░░░░░░████████████▒▒▒▒▒▒▒▒░░░░████░░░░████████████████████████████████████░░░░██",
        "                  ████░░░░░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓░░░░░░░░░░░░░░░░░░██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓░░░░░░████░░░░████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "                  ████░░░░░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓░░░░░░░░░░░░░░░░░░██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒░░░░░░████░░░░██████▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░██",
        "                  ██▓▓░░░░░░██▓▓▓▓▓▓▓▓▓▓██████████████████████████████████▓▓▒▒▒▒▒▒▒▒░░░░░░████░░░░████▓▓▓▓▓▓▓▓▓▓▓▓██████████████▓▓▓▓██░░░░██",
        "                  ██▓▓░░░░░░██▓▓▓▓▓▓▓▓▓▓▓▓██████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████▓▓░░░░░░████░░░░██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██████░░░░██",
        "                  ████░░░░░░██████████████████████████████████████████████████████▓▓░░░░░░████░░░░████████████████████████████████████░░░░██",
        "                  ██▓▓░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██▓▓░░░░░░████░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██",
        "                  ██▓▓░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░████░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██",
        "                  ██▓▓░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██",
        "                  ██▓▓██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"};

    for (auto x : chest)
    {
        int_ra_giua_tua_de(x, 82, 150);
    }
    SetColor(7);
    in_video_kho_bau(ten_file);
}

void Hra(Character *player, vector<int> mat_ma, const char *ten_file)
{
    int mistake = 0;

    if (level1(player) == 0)
    {
        SetColor(13);
        in_ra_giua("Stíny tentokrát ustoupily tvé vůli. Z hlubin se vynořilo první zapomenuté číslo", 170);
        Sleep(3000);
        xoa_bang(1);

        SetColor(14);
        in_ra_giua(to_string(mat_ma[0]), 170);
        SetColor(7);

        Sleep(3000);
        xoa_bang(1);
    }
    else
    {
        SetColor(12);
        in_ra_giua("Stíny zaznamenaly tvé zaváhání. Část tajemství se rozplynula v prázdnotě – první číslo ti zůstává skryto.", 180);
        SetColor(7);
        mistake++;
    }

    if (level2(player) == 0)
    {
        SetColor(13);
        in_ra_giua("Stíny tentokrát ustoupily tvé vůli. Z hlubin se vynořilo druhé zapomenuté číslo", 170);
        Sleep(3000);
        xoa_bang(1);

        SetColor(14);
        in_ra_giua(to_string(mat_ma[1]), 170);
        SetColor(7);

        Sleep(3000);
        xoa_bang(1);
    }
    else
    {
        SetColor(12);
        in_ra_giua("Stíny zaznamenaly tvé zaváhání. Část tajemství se rozplynula v prázdnotě – druhé číslo ti zůstává skryto.", 180);
        SetColor(7);
        mistake++;
    }

    if (level3(player) == 0)
    {
        SetColor(13);
        in_ra_giua("Stíny tentokrát ustoupily tvé vůli. Z hlubin se vynořilo třetí zapomenuté číslo", 170);
        Sleep(3000);
        xoa_bang(1);

        SetColor(14);
        in_ra_giua(to_string(mat_ma[2]), 170);
        SetColor(7);

        Sleep(3000);
        xoa_bang(1);
    }
    else
    {
        SetColor(12);
        in_ra_giua("Stíny zaznamenaly tvé zaváhání. Část tajemství se rozplynula v prázdnotě – třetí číslo ti zůstává skryto.", 180);
        SetColor(7);
        mistake++;
    }

    if (level4(player) == 0)
    {
        SetColor(13);
        in_ra_giua("Stíny tentokrát ustoupily tvé vůli. Z hlubin se vynořilo čtvrté zapomenuté číslo", 170);
        Sleep(3000);
        xoa_bang(1);

        SetColor(14);
        in_ra_giua(to_string(mat_ma[3]), 170);
        SetColor(7);

        Sleep(3000);
        xoa_bang(1);
    }
    else
    {
        SetColor(12);
        in_ra_giua("Stíny zaznamenaly tvé zaváhání. Část tajemství se rozplynula v prázdnotě – čtvrté číslo ti zůstává skryto.", 180);
        SetColor(7);
        mistake++;
    }

    if (level5(player) == 0)
    {
        SetColor(13);
        in_ra_giua("Stíny tentokrát ustoupily tvé vůli. Z hlubin se vynořilo páté zapomenuté číslo", 170);
        Sleep(3000);
        xoa_bang(1);

        SetColor(14);
        in_ra_giua(to_string(mat_ma[4]), 170);
        SetColor(7);

        Sleep(3000);
        xoa_bang(1);
    }
    else
    {
        SetColor(12);
        in_ra_giua("Stíny zaznamenaly tvé zaváhání. Část tajemství se rozplynula v prázdnotě – páté číslo ti zůstává skryto.", 180);
        SetColor(7);
        mistake++;
    }

    SetColor(8);
    closed_chest();
    SetColor(7);

    string choice;
    if (mistake == 5)
    {
        SetColor(13);
        in_ra_giua("Tvá ruka selhala a tajemství ti uniklo. Troufáš si číslo uhodnout ze stínů?", 170);
        SetColor(7);
        cout << "ano/ne: ";
        cin >> choice;
        if (choice == "ano")
        {
            xoa_bang(2);
            int ket_qua = loop_doan_so_5mistake(mat_ma);
            if (ket_qua == 0)
            {
                vyhra(ten_file);
            }
            else
                exit(0);
        }
        else
        {
            SetColor(12);
            in_ra_giua("Tvá ruka se zachvěla. Rozhodl jsi se nečelit osudu – poklad si počká na někoho odvážnějšího", 150);
            SetColor(7);
            exit(0);
        }
    }
    else if (mistake < 5 && mistake > 0)
    {
        SetColor(13);
        in_ra_giua("Temnota ustoupila tvé vůli… avšak tvé chyby rozptýlily některá čísla do prázdna. Vrať je zpět.", 180);
        SetColor(7);
        if (loop_doan_so_it_hon_5mistake(mat_ma) == 0)
        {
            vyhra(ten_file);
        }
        else
            exit(0);
    }
    else if (mistake == 0)
    {
        SetColor(10);
        in_ra_giua("Stíny se podvolily tvé vůli. Nic nebylo ztraceno.", 180);
        SetColor(7);
        if (doan_so_zeromistake(mat_ma) == 0)
        {
            vyhra(ten_file);
        }
        else
            exit(0);
    }
}

int main()
{
    srand(time(0));
    system("chcp 65001"); // UTF-8 podpora
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // in_tua_de();
    Character player;
    tao_player(&player);
    // vector<int> mat_ma;
    // mat_ma_cua_kho_bau(mat_ma);
    // Hra(&player,mat_ma,"poklad.txt");
    level1(&player);
    

    return 0;
}