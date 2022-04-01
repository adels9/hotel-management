#ifndef KLASE_H
#define KLASE_H

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#include <iomanip>
using namespace std;

class Hotel
{
    private:
        char jmbg[14];
        char ime[15];
        char prezime[20];
        char drzavljanstvo[10];
        int godine;
        int iskustvo;
        char org_jed[4];
        char dokument[4];
        char soba_broj[4];
        char soba_vrsta[15];
        char soba_sprat[30];
        char soba_sadrzaj[50];
        char soba_status[20];
        char orgjed_ime[4];
        char rezervacija_broj[10];
        char rezervacija_status[20];
        char pogodnost_ime[4];
        void radnici_meni(void);
        void radnik(int);
        void sobe_meni(void);
        void sobe(int);
        void rezervacije_meni(void);
        void rezervacije(int);
        void pogodnosti_meni(void);
        void pogodnosti(int);
        void orgjed_meni(void);
        void dodaj_orgjed(void);
        void izbrisi_orgjed(void);
        void pregledaj_orgjed(void);
        void clanovi_orgjed(void);
        void gosti_meni(void);
        void gost(int);
        void nazad(void);
    public:
        void Izbor(void);
};
#endif
