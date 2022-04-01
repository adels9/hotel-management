#include "klase.h"

        void Hotel::radnici_meni()
        {
            system("cls");
            cout<<"\n\n 1. Pregled liste zaposlenih\n 2. Detalji o zaposlenim\n 3. Uredjivanje podataka\n 4. Dodavanje informacija\n 5. Brisanje informacija\n 6. Povratak na glavni meni";
            cout<<"\n\n Unesite vas izbor: ";
            int izbor_liste;
            cin>>izbor_liste;
            switch (izbor_liste)
            {
                case 1:
                    radnik(1);
                    break;
                case 2:
                    radnik(2);
                    break;
                case 3:
                    radnik(3);
                    break;
                case 4:
                    radnik(4);
                    break;
                case 5:
                    radnik(5);
                    break;
                case 6:
                    nazad();
                    return;
                default:
                    cout<<"\nPogresan izbor.\n";
                    sleep(3);
                    radnici_meni();
                    break;
            }
        }

        void Hotel::radnik(int broj)
        {
            if(broj == 1)
            {
                system("cls");
                FILE *file;
                file= fopen("radnici.txt", "r");
                cout<<"\n\t\t\t\t\t\t Lista radnika\n";
                cout<<"------------------------------------------------------------------------------------------------------------";
                while(fscanf(file, "%s %s %s %d %d %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &iskustvo, &org_jed[0])!= EOF)
                {
                    cout<<"\nIme: "<<ime<<"\tPrezime: "<<prezime<<"\tJMBG: "<<jmbg<<"\tGodine: "<<godine<<"\tIskustvo: "<<iskustvo<<"\tOrg: "<<org_jed;
                    cout<<"\n------------------------------------------------------------------------------------------------------------";
                }
                fclose(file);
                nazad();

            }
            else if(broj == 2)
            {
                system("cls");
                FILE *file;
                char jmbg_provjera[14];
                cout<<"\nUpisite JMBG radnika cije informacije zelite pregledati: ";
                cin>>jmbg_provjera;
                file= fopen("radnici.txt", "r");
                while(fscanf(file, "%s %s %s %d %d %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &iskustvo, &org_jed[0])!= EOF)
                if(strcmp(jmbg, jmbg_provjera)==0)
                {

                    cout<<"\n---------------------";
                    cout<<"\nIme: "<<ime<<" "<<prezime ;
                    cout<<"\n---------------------";
                    cout<<"\nGodine: "<<godine;
                    cout<<"\n---------------------";
                    cout<<"\nIskustvo: "<<iskustvo;
                    cout<<"\n---------------------";
                    cout<<"\nOrg. jed: "<<org_jed;
                    cout<<"\n---------------------";
                    nazad();
                }
                fclose(file);
            }
            else if(broj == 3)
            {
                system("cls");
                char jmbg_provjera[14], n_prezime[20], n_org_jed[4], n_dokument[4];
                int izbor, n_godine, n_iskustvo;
                cout<<"\nUpisite JMBG radnika cije informacije zelite urediti: ";
                cin>>jmbg_provjera;
                FILE *file, *tempfile;
                file= fopen("radnici.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &iskustvo, &org_jed[0])!= EOF)
                {
                    if(strcmp(jmbg_provjera, jmbg)==0)
                    {
                        cout<<"\nUredjujete podatke radnika "<<ime<<" "<<prezime<<", izaberite sta zelite urediti:";
                        cout<<"\n\n1. Prezime\n2. Godine\n3. Iskustvo\n4. Organizacionu jedinicu\n5. Nazad\n";
                        cout<<"\nVas izbor: ";
                        cin>>izbor;
                        switch(izbor)
                        {
                            case 1:
                                system("cls");
                                cout<<"\nUnesite novo prezime:\n";
                                cin>>n_prezime;
                                fprintf(tempfile, "%s %s %s %d %d %s \n", ime, n_prezime, jmbg, godine, iskustvo, org_jed);
                                cout<<"\nNovo prezime "<<n_prezime<<" uspjesno azurirano\n";
                                break;
                            case 2:
                                system("cls");
                                cout<<"\nUnesite nove godine:\n";
                                cin>>n_godine;
                                fprintf(tempfile, "%s %s %s %d %d %s \n", ime, prezime, jmbg, n_godine, iskustvo, org_jed);
                                cout<<"\nGodine uspjesno azurirane na "<<n_godine<<"\n";
                                break;
                            case 3:
                                system("cls");
                                cout<<"\nUnesite novu vrijednost iskustva:\n";
                                cin>>n_iskustvo;
                                fprintf(tempfile, "%s %s %s %d %d %s \n", ime, prezime, jmbg, godine, n_iskustvo, org_jed);
                                cout<<"\nIskustvo uspjesno azurirano na "<<n_iskustvo<<"\n";
                                break;
                            case 4:
                                system("cls");
                                cout<<"\nUnesite novu organizacionu jedinicu (3 slova):\n";
                                cin>>n_org_jed;
                                fprintf(tempfile, "%s %s %s %d %d %s \n", ime, prezime, jmbg, godine, iskustvo, n_org_jed);
                                cout<<"\nOrganizaciona jedinica uspjesno azurirana na "<<n_org_jed<<"\n";
                                break;
                            case 5:
                                system("cls");
                                cout<<"\nVracamo vas na meni";
                                fprintf(tempfile, "%s %s %s %d %d %s \n", ime, prezime, jmbg, godine, iskustvo, org_jed);
                                break;
                        }
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %s %d %d %s \n", ime, prezime, jmbg, godine, iskustvo, org_jed);
                    }
                }
                fclose(file);
                fclose(tempfile);
                remove("radnici.txt");
                rename("temp.txt", "radnici.txt");
                sleep(3);
                radnici_meni();
            }
            else if(broj == 4)
            {
                system("cls");
                cout<<"\n Ime: ";
                cin>>ime;
                cout<<"\n Prezime: ";
                cin>>prezime;
                cout<<"\n JMBG: ";
                cin>>jmbg;
                cout<<"\n Godine: ";
                cin>>godine;
                cout<<"\n Iskustvo: ";
                cin>>iskustvo;
                cout<<"\n Organizaciona jedinica(3 slova): ";
                cin>>org_jed;

                char c;
                cout<<"\nUpisite 'd' da spremite podatke\n";
                cin>>c;
                if(c=='d')
                {
                    FILE  *file;
                    file= fopen("radnici.txt","a");
                    fprintf(file, "%s %s %s %d %d %s\n", ime, prezime, jmbg, godine, iskustvo, org_jed);
                    fclose(file);
                    cout<<"\nRadnik "<<ime<<" "<<prezime<<" je dodan u bazu.\n";
                    sleep(2);
                    radnici_meni();
                }
                else
                {
                    cout<<"\nOdustali ste od dodavanja radnika.";
                    sleep(3);
                    radnici_meni();
                }
            }
            else if(broj == 5)
            {
                system("cls");
                char jmbg_provjera[14], c;
                cout<<"\nUpisite JMBG radnika kojeg zelite izbrisati: ";
                cin>>jmbg_provjera;
                cout<<"\n\n\nPotvrda\nUpisite 'd' za potvrdu\n";
                cin>>c;
                if(c=='d')
                {
                    FILE *file, *tempfile;
                    file= fopen("radnici.txt", "r");
                    tempfile= fopen("temp.txt", "w");
                    while(fscanf(file, "%s %s %s %d %d %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &iskustvo, &org_jed[0])!= EOF)
                    if(strcmp(jmbg_provjera, jmbg)!=0) fprintf(tempfile, "%s %s %s %d %d %s \n", ime, prezime, jmbg, godine, iskustvo, org_jed);
                    cout<<"\nUspjesno ste obrisali radnika.\n";
                    fclose(file);
                    fclose(tempfile);
                    remove("radnici.txt");
                    rename("temp.txt", "radnici.txt");
                    nazad();
                }
                else
                {
                    cout<<"\nOdustali ste od brisanja.";
                    sleep(3);
                    radnici_meni();
                }
            }
        }

        void Hotel::gosti_meni(void)
        {
            system("cls");
            cout<<"\n\n 1. Pregled liste\n 2. Detalji o gostu\n 3. Uredjivanje podataka\n 4. Dodavanje informacija\n 5. Brisanje informacija\n 6. Povratak na glavni meni";
            cout<<"\n\n Unesite vas izbor: ";
            int izbor_liste;
            cin>>izbor_liste;
            switch (izbor_liste)
            {
                case 1:
                    gost(1);
                    break;
                case 2:
                    gost(2);
                    break;
                case 3:
                    gost(3);
                    break;
                case 4:
                    gost(4);
                    break;
                case 5:
                    gost(5);
                    break;
                case 6:
                    nazad();
                    return;
                default:
                    cout<<"\nPogresan izbor.\n";
                    sleep(3);
                    gosti_meni();
                    break;
            }
        }

        void Hotel::gost(int broj)
        {
            if(broj == 1)
            {
                system("cls");
                FILE *file;
                file= fopen("gosti.txt", "r");
                cout<<"\n\t\t\t\t\t\t Lista\n";
                cout<<"------------------------------------------------------------------------------------------------------------------";
                while(fscanf(file, "%s %s %s %d %s %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &drzavljanstvo[0], &soba_broj[0])!= EOF)
                {
                    cout<<"\nIme: "<<ime<<"\tPrezime: "<<prezime<<"\tJMBG: "<<jmbg<<"\tGodine: "<<godine<<"\tDrzavljanstvo: "<<drzavljanstvo<<"\tSoba: "<<soba_broj;
                    cout<<"\n------------------------------------------------------------------------------------------------------------------";
                }
                fclose(file);
                nazad();

            }
            else if(broj == 2)
            {
                system("cls");
                FILE *file;
                char jmbg_provjera[14];
                cout<<"\nUpisite JMBG gosta cije informacije zelite pregledati: ";
                cin>>jmbg_provjera;
                file= fopen("gosti.txt", "r");
                while(fscanf(file, "%s %s %s %d %s %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &drzavljanstvo[0], &soba_broj[0])!= EOF)
                if(strcmp(jmbg, jmbg_provjera)==0)
                {

                    cout<<"\n---------------------";
                    cout<<"\nIme: "<<ime<<" "<<prezime ;
                    cout<<"\n---------------------";
                    cout<<"\nGodine: "<<godine;
                    cout<<"\n---------------------";
                    cout<<"\nDrzavljanstvo: "<<drzavljanstvo;
                    cout<<"\n---------------------";
                    cout<<"\nBroj sobe: "<<soba_broj;
                    cout<<"\n---------------------";
                    nazad();
                }
                fclose(file);
            }
            else if(broj == 3)
            {
                system("cls");
                char jmbg_provjera[14], n_prezime[20], n_drzavljanstvo[10], n_broj[4];
                int izbor, n_godine;
                cout<<"\nUpisite JMBG gosta cije informacije zelite urediti: ";
                cin>>jmbg_provjera;
                FILE *file, *tempfile;
                file= fopen("gosti.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %s %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &drzavljanstvo[0], &soba_broj[0])!= EOF)
                {
                    if(strcmp(jmbg_provjera, jmbg)==0)
                    {
                        cout<<"\nUredjujete podatke gosta"<<ime<<" "<<prezime<<", izaberite sta zelite urediti:";
                        cout<<"\n\n1. Prezime\n2. Godine\n3. Drzavljanstvo\n4. Broj sobe\n5. Nazad\n";
                        cout<<"\nVas izbor: ";
                        cin>>izbor;
                        switch(izbor)
                        {
                            case 1:
                                system("cls");
                                cout<<"\nUnesite novo prezime:\n";
                                cin>>n_prezime;
                                fprintf(tempfile, "%s %s %s %d %s %s \n", ime, n_prezime, jmbg, godine, drzavljanstvo, soba_broj);
                                cout<<"\nNovo prezime "<<n_prezime<<" uspjesno azurirano\n";
                                break;
                            case 2:
                                system("cls");
                                cout<<"\nUnesite nove godine:\n";
                                cin>>n_godine;
                                fprintf(tempfile, "%s %s %s %d %s %s \n", ime, prezime, jmbg, n_godine, drzavljanstvo, soba_broj);
                                cout<<"\nGodine uspjesno azurirane na "<<n_godine<<"\n";
                                break;
                            case 3:
                                system("cls");
                                cout<<"\nUnesite novo drzavljanstvo:\n";
                                cin>>n_drzavljanstvo;
                                fprintf(tempfile, "%s %s %s %d %s %s \n", ime, prezime, jmbg, godine, n_drzavljanstvo, soba_broj);
                                cout<<"\nDrzavljanstvo uspjesno azurirano na "<<n_drzavljanstvo<<"\n";
                                break;
                            case 4:
                                system("cls");
                                cout<<"\nUnesite novi broj sobe:\n";
                                cin>>n_broj;
                                fprintf(tempfile, "%s %s %s %d %s %s \n", ime, prezime, jmbg, godine, drzavljanstvo, n_broj);
                                cout<<"\nBroj sobe uspjesno azuriran na "<<n_broj<<"\n";
                                break;
                            case 5:
                                system("cls");
                                cout<<"\nVracamo vas na meni";
                                fprintf(tempfile, "%s %s %s %d %s %s \n", ime, prezime, jmbg, godine, drzavljanstvo, soba_broj);
                                break;
                        }
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %s %d %s %s \n", ime, prezime, jmbg, godine, drzavljanstvo, soba_broj);
                    }
                }
                fclose(file);
                fclose(tempfile);
                remove("gosti.txt");
                rename("temp.txt", "gosti.txt");
                sleep(3);
                gosti_meni();
            }
            else if(broj == 4)
            {
                system("cls");
                cout<<"\n Ime: ";
                cin>>ime;
                cout<<"\n Prezime: ";
                cin>>prezime;
                cout<<"\n JMBG: ";
                cin>>jmbg;
                cout<<"\n Godine: ";
                cin>>godine;
                cout<<"\n Drzavljanstvo: ";
                cin>>drzavljanstvo;
                cout<<"\n Broj sobe: ";
                cin>>soba_broj;

                char c;
                cout<<"\nUpisite 'd' da spremite podatke\n";
                cin>>c;
                if(c=='d')
                {
                    FILE  *file;
                    file= fopen("gosti.txt","a");
                    fprintf(file, "%s %s %s %d %s %s\n", ime, prezime, jmbg, godine, drzavljanstvo, soba_broj);
                    fclose(file);
                    cout<<"\nGost "<<ime<<" "<<prezime<<" je dodan u bazu.\n";
                    sleep(2);
                    gosti_meni();
                }
                else
                {
                    cout<<"\nOdustali ste od dodavanja gosta.";
                    sleep(3);
                    gosti_meni();
                }
            }
            else if(broj == 5)
            {
                system("cls");
                char jmbg_provjera[14], c;
                cout<<"\nUpisite JMBG gosta kojeg zelite izbrisati: ";
                cin>>jmbg_provjera;
                cout<<"\n\n\nPotvrda\nUpisite 'd' za potvrdu\n";
                cin>>c;
                if(c=='d')
                {
                    FILE *file, *tempfile;
                    file= fopen("gosti.txt", "r");
                    tempfile= fopen("temp.txt", "w");
                    while(fscanf(file, "%s %s %s %d %s %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &drzavljanstvo[0], &soba_broj[0])!= EOF)
                    if(strcmp(jmbg_provjera, jmbg)!=0) fprintf(tempfile, "%s %s %s %d %s %s \n", ime, prezime, jmbg, godine, drzavljanstvo, soba_broj);
                    cout<<"\nUspjesno ste obrisali gosta.\n";
                    fclose(file);
                    fclose(tempfile);
                    remove("gosti.txt");
                    rename("temp.txt", "gosti.txt");
                    nazad();
                }
                else
                {
                    cout<<"\nOdustali ste od brisanja.";
                    sleep(3);
                    gosti_meni();
                }
            }
        }

        void Hotel::rezervacije_meni(void)
        {
            system("cls");
            cout<<"\n\n 1. Dodaj rezervaciju\n 2. Azuriraj rezervaciju\n 3. Izbrisi rezervaciju\n 4. Pregledaj rezervaciju\n 5. Pregledaj sve rezervacije\n 6. Povratak na glavni meni";
            cout<<"\n\n Unesite vas izbor: ";
            int izbor_liste;
            cin>>izbor_liste;

            switch (izbor_liste)
            {
                case 1:
                    rezervacije(1);
                    break;
                case 2:
                    rezervacije(2);
                    break;
                case 3:
                    rezervacije(3);
                    break;
                case 4:
                    rezervacije(4);
                    break;
                case 5:
                    rezervacije(5);
                    break;
                case 6:
                    nazad();
                    break;
                default:
                    cout<<"\nPogresan izbor\n";
                    sleep(3);
                    rezervacije_meni();
                    break;
            }
        }

        void Hotel::rezervacije(int broj)
        {
            system("cls");
            int dok_izbor;
            if(broj == 1)
            {
                cout<<"\n Unesite broj rezervacije (01, 02): ";
                cin>>rezervacija_broj;
                cout<<"\n Ime: ";
                cin>>ime;
                cout<<"\n Prezime: ";
                cin>>prezime;
                cout<<"\n JMBG: ";
                cin>>jmbg;
                cout<<"\n Broj sobe: ";
                cin>>soba_broj;
                cout<<"\n Status rezervacije:\n 1. Na cekanju\n 2. Zavrseno\n\n Vas izbor: ";
                cin>>dok_izbor;
                switch(dok_izbor)
                {
                    case 1:
                        strcpy(rezervacija_status, "Cekanje");
                        break;
                    case 2:
                        strcpy(rezervacija_status, "Zavrseno");
                        break;
                    default:
                        strcpy(rezervacija_status, "Nepoznato");
                        break;
                }
                FILE  *file;
                file= fopen("rezervacije.txt","a");
                fprintf(file, "%s %s %s %s %s %s\n", rezervacija_broj, ime, prezime, jmbg, soba_broj, rezervacija_status);
                fclose(file);
                cout<<"\nRezervacija broj "<<rezervacija_broj<<" je dodana u bazu.\n";
                sleep(2);
                rezervacije_meni();
            }
            else if(broj == 2)
            {
                char d_broj[4], jmbg_provjera[14], n_ime[20], n_prezime[20], soba_nbroj[4], rezervacija_nstatus[20];
                int izbor, n_godine;
                cout<<"\nUpisite broj rezervacije koju zelite urediti: ";
                cin>>d_broj;
                FILE *file, *tempfile;
                file= fopen("rezervacije.txt", "r");
                tempfile= fopen("tempdoc.txt", "w");
                while(fscanf(file, "%s %s %s %s %s %s", &rezervacija_broj[0], &ime[0] , &prezime[0], &jmbg[0], &soba_broj[0], &rezervacija_status[0])!= EOF)
                {
                    if(strcmp(d_broj, rezervacija_broj)==0)
                    {
                        cout<<"\nUredjujete rezervaciju "<<rezervacija_broj<<", izaberite sta zelite urediti: ";
                        cout<<"\n\n 1. Ime\n 2. Prezime\n 3. Broj sobe\n 4. Status rezervacije";
                        cout<<"\n\n Unesite vas izbor: ";
                        cin>>izbor;
                        switch(izbor)
                        {
                            case 1:
                                system("cls");
                                cout<<"\nUnesite novo ime:\n";
                                cin>>n_ime;
                                fprintf(tempfile, "%s %s %s %s %s %s \n", rezervacija_broj, n_ime, prezime, jmbg, soba_broj, rezervacija_status);
                                cout<<"\nNovo ime "<<n_ime<<" uspjesno azurirano\n";
                                break;
                            case 2:
                                system("cls");
                                cout<<"\nUnesite novo prezime:\n";
                                cin>>n_prezime;
                                fprintf(tempfile, "%s %s %s %s %s %s \n", rezervacija_broj, ime, n_prezime, jmbg, soba_broj, rezervacija_status);
                                cout<<"\nPrezime uspjesno azurirano na "<<n_prezime<<"\n";
                                break;
                            case 3:
                                system("cls");
                                cout<<"\nUnesite broj nove sobe:\n";
                                cin>>soba_nbroj;
                                fprintf(tempfile, "%s %s %s %s %s %s \n", rezervacija_broj, ime, prezime, jmbg, soba_nbroj, rezervacija_status);
                                cout<<"\nBroj sobe uspjesno azuriran na "<<soba_nbroj<<"\n";
                                break;
                            case 4:
                                system("cls");
                                cout<<"\nUnesite novi status (Cekanje/Zavrseno):\n";
                                cin>>rezervacija_nstatus;
                                fprintf(tempfile, "%s %s %s %s %s %s \n", rezervacija_broj, ime, prezime, jmbg, soba_broj, rezervacija_nstatus);
                                cout<<"\nNovi status rezervacije uspjesno azuriran na "<<rezervacija_nstatus<<"\n";
                                break;
                            case 5:
                                system("cls");
                                cout<<"\nVracamo vas na meni";
                                fprintf(tempfile, "%s %s %s %s %s %s \n", rezervacija_broj, ime, prezime, jmbg, soba_broj, rezervacija_status);
                                break;
                        }
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %s %s %s %s \n", rezervacija_broj, ime, prezime, jmbg, soba_broj, rezervacija_status);
                    }
                }
                fclose(file);
                fclose(tempfile);
                remove("rezervacije.txt");
                rename("tempdoc.txt", "rezervacije.txt");
                sleep(3);
                rezervacije_meni();
            }
            else if(broj == 3)
            {
                char doc_id[4], c;
                cout<<"\nUpisite broj rezervacije koju zelite izbrisati: ";
                cin>>doc_id;
                cout<<"\n\n\nPotvrda\nUpisite 'd' za potvrdu\n";
                cin>>c;
                if(c=='d')
                {
                    FILE *file, *tempfile;
                    file= fopen("rezervacije.txt", "r");
                    tempfile= fopen("tempdoc.txt", "w");
                    while(fscanf(file, "%s %s %s %s %s %s", &rezervacija_broj[0], &ime[0] , &prezime[0], &jmbg[0], &soba_broj[0], &rezervacija_status[0])!= EOF)
                    if(strcmp(rezervacija_broj, doc_id)!=0) fprintf(tempfile, "%s %s %s %s %s %s \n", rezervacija_broj, ime, prezime, jmbg, soba_broj, rezervacija_status);
                    cout<<"\nUspjesno ste obrisali rezervaciju.\n";
                    fclose(file);
                    fclose(tempfile);
                    remove("rezervacije.txt");
                    rename("tempdoc.txt", "rezervacije.txt");
                    nazad();
                }
                else
                {
                    cout<<"\nOdustali ste od brisanja.";
                    sleep(3);
                    rezervacije_meni();
                }
            }
            else if(broj == 4)
            {
                system("cls");
                FILE *file;
                char doc_id[4];
                cout<<"\nUpisite broj rezervacije koju zelite pregledati: ";
                cin>>doc_id;
                file= fopen("rezervacije.txt", "r");
                while(fscanf(file, "%s %s %s %s %s %s", &rezervacija_broj[0], &ime[0] , &prezime[0], &jmbg[0], &soba_broj[0], &rezervacija_status[0])!= EOF)
                if(strcmp(rezervacija_broj, doc_id)==0)
                {

                    cout<<"\n---------------------------------------";
                    cout<<"\nIme: "<<ime;
                    cout<<"\n---------------------------------------";
                    cout<<"\nPrezime: "<<prezime;
                    cout<<"\n---------------------------------------";
                    cout<<"\nJMBG: "<<jmbg;
                    cout<<"\n---------------------------------------";
                    cout<<"\nBroj sobe: "<<soba_broj;
                    cout<<"\n---------------------------------------";
                    cout<<"\nStatus rezervacije: "<<rezervacija_status;
                    cout<<"\n---------------------------------------";
                }
                fclose(file);
                nazad();
            }
            else if(broj == 5)
            {
                FILE *file;
                file= fopen("rezervacije.txt", "r");
                cout<<"\n\t\t\t\t Lista rezervacija\n";
                cout<<"--------------------------------------------------------------------------------------------------";
                while(fscanf(file, "%s %s %s %s %s %s", &rezervacija_broj[0], &ime[0] , &prezime[0], &jmbg[0], &soba_broj[0], &rezervacija_status[0])!= EOF)
                {
                    cout<<"\nBroj rezervacije: "<<rezervacija_broj<<"\tIme: "<<ime<<" "<<prezime<<"\tJMBG: "<<jmbg<<"\tBroj sobe: "<<soba_broj<<"\tStatus: "<<rezervacija_status;
                    cout<<"\n--------------------------------------------------------------------------------------------------";
                }
                fclose(file);
                nazad();
            }
        }

        void Hotel::sobe_meni(void)
        {
            system("cls");
            cout<<"\n\n 1. Dodaj sobu\n 2. Azuriraj sobu\n 3. Izbrisi sobu\n 4. Pregledaj detalje\n 5. Pregledaj sve sobe\n 6. Povratak na glavni meni";
            cout<<"\n\n Unesite vas izbor: ";
            int izbor_liste;
            cin>>izbor_liste;

            switch (izbor_liste)
            {
                case 1:
                    sobe(1);
                    break;
                case 2:
                    sobe(2);
                    break;
                case 3:
                    sobe(3);
                    break;
                case 4:
                    sobe(4);
                    break;
                case 5:
                    sobe(5);
                    break;
                case 6:
                    nazad();
                    break;
                default:
                    cout<<"\nPogresan izbor\n";
                    sleep(3);
                    sobe_meni();
                    break;
            }
        }

        void Hotel::sobe(int broj)
        {
            system("cls");
            int dok_izbor;
            if(broj == 1)
            {
                cout<<"\n Unesite broj sobe (01, 02): ";
                cin>>soba_broj;
                cout<<"\n Izaberite vrstu sobe:\n";
                cout<<" 1. Jednokrevetna\n";
                cout<<" 2. Dvokrevetna\n";
                cout<<" 3. Trokrevetna\n";
                cout<<" 4. Premium\n";
                cout<<"\n Vas izbor: ";
                cin>>dok_izbor;
                switch(dok_izbor)
                {
                    case 1:
                        strcpy(soba_vrsta, "Jednokrevetna");
                        break;
                    case 2:
                        strcpy(soba_vrsta, "Dvokrevetna");
                        break;
                    case 3:
                        strcpy(soba_vrsta, "Trokrevetna");
                        break;
                    case 4:
                        strcpy(soba_vrsta, "Premium");
                        break;
                    default:
                        strcpy(soba_vrsta, "Nepoznato");
                        break;
                }
                cout<<"\n Unesite sprat sobe (Prvi, drugi): ";
                cin.ignore();
                cin.getline(soba_sprat, 29);
                cout<<"\n Unesite dodatne pogodnosti: ";
                cin.getline(soba_sadrzaj, 49);
                cout<<"\n Izaberite status sobe:";
                cout<<"\n 1. Slobodno";
                cout<<"\n 2. Zauzeto";
                cout<<"\n 3. Rezervisano";
                cout<<"\n Vas izbor: ";
                cin>>dok_izbor;
                switch(dok_izbor)
                {
                    case 1:
                        strcpy(soba_status, "Slobodno");
                        break;
                    case 2:
                        strcpy(soba_status, "Zauzeto");
                        break;
                    case 3:
                        strcpy(soba_status, "Rezervisano");
                        break;
                    default:
                        strcpy(soba_status, "Nepoznato");
                        break;
                }
                FILE  *file;
                file= fopen("sobe.txt","a");
                fprintf(file, "%s %s %s %s %s \n", soba_broj, soba_vrsta, soba_sprat, soba_sadrzaj, soba_status);
                fclose(file);
                cout<<"\nSoba broj "<<soba_broj<<" je dodana u bazu.\n";
                sleep(2);
                sobe_meni();
            }
            else if(broj == 2)
            {
                char d_broj[4], n_vrsta[15], n_vlasnik[30], n_sadrzaj[50], soba_nstatus[20];
                int d_izbor, n_vrstaizb;
                cout<<"\nUpisite broj sobe koju zelite urediti: ";
                cin>>d_broj;
                FILE *file, *tempfile;
                file= fopen("sobe.txt", "r");
                tempfile= fopen("tempdoc.txt", "w");
                while(fscanf(file, "%s %s %s %s %s", &soba_broj[0], &soba_vrsta[0] , &soba_sprat[0], &soba_sadrzaj[0], &soba_status[0])!= EOF)
                {
                    if(strcmp(d_broj, soba_broj)==0)
                    {
                        cout<<"\nUredjujete sobu "<<soba_broj<<", izaberite sta zelite urediti: ";
                        cout<<"\n\n 1. Vrstu sobe\n 2. Sprat sobe\n 3. Dodatne pogodnosti\n 4. Status";
                        cout<<"\n\n Unesite vas izbor: ";
                        cin>>d_izbor;
                        switch(d_izbor)
                        {
                            case 1:
                                cout<<"\n Izaberite vrstu sobe:\n";
                                cout<<" 1. Jednokrevetna\n";
                                cout<<" 2. Dvokrevetna\n";
                                cout<<" 3. Trokrevetna\n";
                                cout<<" 4. Premium\n";
                                cout<<"\n Vas izbor: ";
                                cin>>n_vrstaizb;
                                switch(n_vrstaizb)
                                {
                                    case 1:
                                        strcpy(n_vrsta, "Jednokrevetna");
                                        break;
                                    case 2:
                                        strcpy(n_vrsta, "Dvokrevetna");
                                        break;
                                    case 3:
                                        strcpy(n_vrsta, "Trokrevetna");
                                        break;
                                    case 4:
                                        strcpy(n_vrsta, "Premium");
                                        break;
                                    default:
                                        strcpy(n_vrsta, "Nepoznato");
                                        break;
                                }
                                fprintf(tempfile, "%s %s %s %s %s \n", soba_broj, n_vrsta, soba_sprat, soba_sadrzaj, soba_status);
                                cout<<"\nVrsta sobe uspjesno azurirana na "<<n_vrsta<<"\n";
                                break;
                            case 2:
                                cout<<"\nUnesite novi sprat sobe: \n";
                                cin.ignore();
                                cin.getline(n_vlasnik, 29);
                                fprintf(tempfile, "%s %s %s %s %s \n", soba_broj, soba_vrsta, n_vlasnik, soba_sadrzaj, soba_status);
                                cout<<"\nSprat sobe uspjesno azuriran na "<<n_vlasnik<<"\n";
                                break;
                            case 3:
                                cout<<"\nUnesite nove pogodnosti sobe: \n";
                                cin.ignore();
                                cin.getline(n_sadrzaj, 49);
                                fprintf(tempfile, "%s %s %s %s %s \n", soba_broj, soba_vrsta, soba_sprat, n_sadrzaj, soba_status);
                                cout<<"\nPogodnosti sobe uspjesno azurirane na "<<n_sadrzaj<<"\n";
                                break;
                            case 4:
                                cout<<"\n Izaberite novi status sobe:";
                                cout<<"\n 1. Slobodno";
                                cout<<"\n 2. Zauzeto";
                                cout<<"\n 3. Rezervisano";
                                cout<<"\n Vas izbor: ";
                                cin>>dok_izbor;
                                switch(dok_izbor)
                                {
                                    case 1:
                                        strcpy(soba_nstatus, "Slobodno");
                                        break;
                                    case 2:
                                        strcpy(soba_nstatus, "Zauzeto");
                                        break;
                                    case 3:
                                        strcpy(soba_nstatus, "Rezervisano");
                                        break;
                                    default:
                                        strcpy(soba_nstatus, "Nepoznato");
                                        break;
                                }
                                fprintf(tempfile, "%s %s %s %s %s \n", soba_broj, soba_vrsta, soba_sprat, soba_sadrzaj, soba_nstatus);
                                cout<<"\nStatus sobe uspjesno azuriran na "<<soba_nstatus<<"\n";
                                break;
                        }
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %s %s %s \n", soba_broj, soba_vrsta, soba_sprat, soba_sadrzaj, soba_status);
                    }
                }
                fclose(file);
                fclose(tempfile);
                remove("sobe.txt");
                rename("tempdoc.txt", "sobe.txt");
                sleep(3);
                sobe_meni();
            }
            else if(broj == 3)
            {
                char doc_id[4], c;
                cout<<"\nUpisite broj sobe koju zelite izbrisati: ";
                cin>>doc_id;
                cout<<"\n\n\nPotvrda\nUpisite 'd' za potvrdu\n";
                cin>>c;
                if(c=='d')
                {
                    FILE *file, *tempfile;
                    file= fopen("sobe.txt", "r");
                    tempfile= fopen("tempdoc.txt", "w");
                    while(fscanf(file, "%s %s %s %s %s", &soba_broj[0], &soba_vrsta[0] , &soba_sprat[0], &soba_sadrzaj[0], &soba_status[0])!= EOF)
                    if(strcmp(soba_broj, doc_id)!=0) fprintf(tempfile, "%s %s %s %s %s \n", soba_broj, soba_vrsta, soba_sprat, soba_sadrzaj, soba_status);
                    cout<<"\nUspjesno ste obrisali sobu.\n";
                    fclose(file);
                    fclose(tempfile);
                    remove("sobe.txt");
                    rename("tempdoc.txt", "sobe.txt");
                    nazad();
                }
                else
                {
                    cout<<"\nOdustali ste od brisanja.";
                    sleep(3);
                    sobe_meni();
                }
            }
            else if(broj == 4)
            {
                system("cls");
                FILE *file;
                char doc_id[4];
                cout<<"\nUpisite broj sobe koju zelite pregledati: ";
                cin>>doc_id;
                file= fopen("sobe.txt", "r");
                while(fscanf(file, "%s %s %s %s %s", &soba_broj[0], &soba_vrsta[0] , &soba_sprat[0], &soba_sadrzaj[0], &soba_status[0])!= EOF)
                if(strcmp(soba_broj, doc_id)==0)
                {

                    cout<<"\n---------------------------------------";
                    cout<<"\nBroj sobe: "<<soba_broj;
                    cout<<"\n---------------------------------------";
                    cout<<"\nVrsta sobe: "<<soba_vrsta;
                    cout<<"\n---------------------------------------";
                    cout<<"\nSprat: "<<soba_sprat;
                    cout<<"\n---------------------------------------";
                    cout<<"\nDodatne pogodnosti: "<<soba_sadrzaj;
                    cout<<"\n---------------------------------------";
                    cout<<"\nStatus sobe: "<<soba_status;
                    cout<<"\n---------------------------------------";
                    nazad();
                }
                fclose(file);
            }
            else if(broj == 5)
            {
                system("cls");
                int izb;
                cout<<"Lista soba\n\n 1. Slobodne\n 2. Zauzete\n 3. Rezervisane\n\n Vas izbor: ";
                cin >>izb;
                switch(izb)
                {
                    case 1:
                        sobe(6);
                        break;
                    case 2:
                        sobe(7);
                        break;
                    case 3:
                        sobe(8);
                        break;
                    default:
                        sobe(5);
                        break;
                }
            }
            else if(broj == 6)
            {
                FILE *file;
                file= fopen("sobe.txt", "r");
                cout<<"\n\t\t\t\t Lista slobodnih soba\n";
                cout<<"--------------------------------------------------------------------------------------------------";
                while(fscanf(file, "%s %s %s %s %s", &soba_broj[0], &soba_vrsta[0] , &soba_sprat[0], &soba_sadrzaj[0], &soba_status[0])!= EOF)
                if(strcmp(soba_status, "Slobodno")==0)
                {
                    cout<<"\nBroj sobe: "<<soba_broj<<"\tVrsta: "<<soba_vrsta<<"\tSprat: "<<soba_sprat<<"\tDodatne pogodnosti: "<<soba_sadrzaj<<"\tStatus sobe: "<<soba_status;
                    cout<<"\n--------------------------------------------------------------------------------------------------";
                }
                fclose(file);
                nazad();
            }
            else if(broj == 7)
            {
                FILE *file;
                file= fopen("sobe.txt", "r");
                cout<<"\n\t\t\t\t Lista zauzetih soba\n";
                cout<<"--------------------------------------------------------------------------------------------------";
                while(fscanf(file, "%s %s %s %s %s", &soba_broj[0], &soba_vrsta[0] , &soba_sprat[0], &soba_sadrzaj[0], &soba_status[0])!= EOF)
                if(strcmp(soba_status, "Zauzeto")==0)
                {
                    cout<<"\nBroj sobe: "<<soba_broj<<"\tVrsta: "<<soba_vrsta<<"\tSprat: "<<soba_sprat<<"\tDodatne pogodnosti: "<<soba_sadrzaj<<"\tStatus sobe: "<<soba_status;
                    cout<<"\n--------------------------------------------------------------------------------------------------";
                }
                fclose(file);
                nazad();
            }
            else if(broj == 8)
            {
                FILE *file;
                file= fopen("sobe.txt", "r");
                cout<<"\n\t\t\t\t Lista rezervisanih soba\n";
                cout<<"--------------------------------------------------------------------------------------------------";
                while(fscanf(file, "%s %s %s %s %s", &soba_broj[0], &soba_vrsta[0] , &soba_sprat[0], &soba_sadrzaj[0], &soba_status[0])!= EOF)
                if(strcmp(soba_status, "Rezervisano")==0)
                {
                    cout<<"\nBroj sobe: "<<soba_broj<<"\tVrsta: "<<soba_vrsta<<"\tSprat: "<<soba_sprat<<"\tDodatne pogodnosti: "<<soba_sadrzaj<<"\tStatus sobe: "<<soba_status;
                    cout<<"\n--------------------------------------------------------------------------------------------------";
                }
                fclose(file);
                nazad();
            }
        }

        void Hotel::pogodnosti_meni(void)
        {
            system("cls");
            cout<<"\n\n 1. Dodaj uslugu\n 2. Izbrisi uslugu\n 3. Pregledaj dostupne usluge\n 4. Povratak na glavni meni";
            cout<<"\n\n Unesite vas izbor: ";
            int izbor_liste;
            cin>>izbor_liste;

            switch (izbor_liste)
            {
                case 1:
                    pogodnosti(1);
                    break;
                case 2:
                    pogodnosti(2);
                    break;
                case 3:
                    pogodnosti(3);
                    break;
                case 4:
                    nazad();
                    break;
                default:
                    cout<<"\nPogresan izbor\n";
                    sleep(3);
                    pogodnosti_meni();
                    break;
            }
        }

        void Hotel::pogodnosti(int broj)
        {
            if(broj == 1)
            {
                system("cls");
                cout<<"\n Unesite ime usluge (3 slova): ";
                cin>>pogodnost_ime;
                FILE  *file;
                file= fopen("pogodnosti.txt","a");
                fprintf(file, "%s \n", pogodnost_ime);
                fclose(file);
                cout<<"\nUsluga "<<pogodnost_ime<<" dodana.\n";
                sleep(2);
                pogodnosti_meni();
            }
            else if(broj == 2)
            {
                system("cls");
                char org[4], c;
                cout<<"\nUpisite naziv usluge koju zelite izbrisati (3 slova): ";
                cin>>org;
                cout<<"\n\n\nPotvrda\nUpisite 'd' za potvrdu\n";
                cin>>c;
                if(c=='d')
                {
                    FILE *file, *tempfile;
                    file= fopen("pogodnosti.txt", "r");
                    tempfile= fopen("temporg.txt", "w");
                    while(fscanf(file, "%s", &pogodnost_ime[0])!= EOF)
                    if(strcmp(pogodnost_ime, org)!=0) fprintf(tempfile, "%s \n", pogodnost_ime);
                    cout<<"\nUspjesno ste uslugu pod nazivom "<<org<<".\n";
                    fclose(file);
                    fclose(tempfile);
                    remove("pogodnosti.txt");
                    rename("temporg.txt", "pogodnosti.txt");
                    nazad();
                }
                else
                {
                    cout<<"\nOdustali ste od brisanja.";
                    sleep(3);
                    pogodnosti_meni();
                }
            }
            else if(broj == 3)
            {
                system("cls");
                FILE *file;
                file= fopen("pogodnosti.txt", "r");
                cout<<"\nDostupne usluge";
                cout<<"\n----------------------";
                while(fscanf(file, "%s", &pogodnost_ime[0])!= EOF)
                cout<<"\n"<<pogodnost_ime;
                cout<<"\n----------------------";
                fclose(file);
                nazad();
            }
        }

        void Hotel::orgjed_meni(void)
        {
            system("cls");
            cout<<"\n\n 1. Dodaj organizacionu jedinicu\n 2. Izbrisi organizacionu jedinicu\n 3. Pregledaj organizacione jedinice\n 4. Pregledaj sve clanove org. jedinice\n 5. Povratak na glavni meni";
            cout<<"\n\n Unesite vas izbor: ";
            int izbor_liste;
            cin>>izbor_liste;

            switch (izbor_liste)
            {
                case 1:
                    dodaj_orgjed();
                    break;
                case 2:
                    izbrisi_orgjed();
                    break;
                case 3:
                    pregledaj_orgjed();
                    break;
                case 4:
                    clanovi_orgjed();
                    break;
                case 5:
                    nazad();
                    break;
                default:
                    cout<<"\nPogresan izbor\n";
                    sleep(3);
                    orgjed_meni();
                    break;
            }
        }

        void Hotel::dodaj_orgjed(void)
        {
            system("cls");
            cout<<"\n Unesite ime organizacione jedinice (3 slova): ";
            cin>>orgjed_ime;
            FILE  *file;
            file= fopen("organizacione_jedinice.txt","a");
            fprintf(file, "%s \n", orgjed_ime);
            fclose(file);
            cout<<"\nOrganizaciona jedinica "<<orgjed_ime<<" dodana.\n";
            sleep(2);
            orgjed_meni();
        }

        void Hotel::izbrisi_orgjed(void)
        {
            system("cls");
            char org[4], c;
            cout<<"\nUpisite naziv organizacione jedinice koju zelite izbrisati (3 slova): ";
            cin>>org;
            cout<<"\n\n\nPotvrda\nUpisite 'd' za potvrdu\n";
            cin>>c;
            if(c=='d')
            {
                FILE *file, *tempfile;
                file= fopen("organizacione_jedinice.txt", "r");
                tempfile= fopen("temporg.txt", "w");
                while(fscanf(file, "%s", &orgjed_ime[0])!= EOF)
                if(strcmp(orgjed_ime, org)!=0) fprintf(tempfile, "%s \n", orgjed_ime);
                cout<<"\nUspjesno ste obrisali organizacionu jedinicu.\n";
                fclose(file);
                fclose(tempfile);
                remove("organizacione_jedinice.txt");
                rename("temporg.txt", "organizacione_jedinice.txt");
                nazad();
            }
            else
            {
                cout<<"\nOdustali ste od brisanja.";
                sleep(3);
                orgjed_meni();
            }
        }

        void Hotel::pregledaj_orgjed(void)
        {
            system("cls");
            FILE *file;
            file= fopen("organizacione_jedinice.txt", "r");
            cout<<"\nOrganizacione jedinice";
            cout<<"\n----------------------";
            while(fscanf(file, "%s", &orgjed_ime[0])!= EOF)
            cout<<"\n"<<orgjed_ime;
            cout<<"\n----------------------";
            fclose(file);
            nazad();
        }

        void Hotel::clanovi_orgjed(void)
        {
            system("cls");
            FILE *file;
            char org[4];
            cout<<"\nUpisite organizacionu jedinicu cije clanove zelite pregledati (3 slova): ";
            cin>>org;
            file= fopen("radnici.txt", "r");
            cout<<"\n\t\t"<<org;
            while(fscanf(file, "%s %s %s %d %d %s %s", &ime[0], &prezime[0] , &jmbg[0], &godine, &iskustvo, &org_jed[0], &dokument[0])!= EOF)
            if(strcmp(org_jed, org)==0)
            {
                cout<<"\n------------------------------------";
                cout<<"\n"<<ime<<" "<<prezime<<" JMBG: "<<jmbg;
            }
            cout<<"\n------------------------------------";
            fclose(file);
            nazad();
        }

        void Hotel::nazad(void)
        {
            cout<<"\n\n\n Pritisnite enter za povratak nazad\n\n";
            cin.get();
            cin.get();
        }

        void Hotel::Izbor(void)
        {
            while(true)
            {
                system("cls");
                cout<<"\n\n Hotel menadzment\n\n 1. Sobe\n 2. Radnici\n 3. Organizacione jedinice\n 4. Gosti\n 5. Rezervacije\n 6. Dodatne usluge\n 7. Izlaz";
                cout<<"\n\n Unesite vas izbor: ";
                int izbor_liste;
                cin>>izbor_liste;

                switch (izbor_liste)
                {
                    case 1:
                        sobe_meni();
                        break;
                    case 2:
                        radnici_meni();
                        break;
                    case 3:
                        orgjed_meni();
                        break;
                    case 4:
                        gosti_meni();
                        break;
                    case 5:
                        rezervacije_meni();
                        break;
                    case 6:
                        pogodnosti_meni();
                        break;
                    case 7:
                        system("CLS");
                        cout<<"\nZatvorili ste program.\n";
                        sleep(5);
                        return;
                    default:
                        cout<<"\nPogresan izbor\n";
                        break;
                }
            }
        }
