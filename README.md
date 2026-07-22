================================================================================
          COMPREHENSIVE CODEBASE DOCUMENTATION (FILE-BY-FILE GUIDE)
================================================================================

Tento dokument slouží jako podrobný průvodce všemi soubory v projektu. Je 
strukturován tak, aby i začátečník přesně pochopil, co který řádek dělá 
a jak do sebe jednotlivé dílky skládačky zapadají.

--------------------------------------------------------------------------------
1. Ucet.h (Hlavičkový soubor bázové třídy)
--------------------------------------------------------------------------------

[ VÝZNAM SOUBORU ]
Toto je hlavní předpis (kontrakt) pro všechny typy účtů v systému. Definuje 
bázovou (rodičovskou) abstraktní třídu Ucet. Sama o sobě neumí vytvořit konkrétní 
účet, ale říká, co musí mít každý účet společné.

[ DETAILNÍ ROZBOR ČÁSTÍ ]

* Protektorovaná data (protected:):
  - protected: 
    Datové členy pod tímto klíčovým slovem nejsou přístupné zvenčí (např. z main()), 
    ale jsou přístupné z odvozených tříd (BeznyUcet, SporiciUcet).
  - std::string cisloUctu;
    Textový řetězec uchovávající identifikátor účtu (např. "CZ-1111").
    Jak pracovat: V dceřiných třídách k němu přistupuješ přímo: this->cisloUctu.
  - std::vector<double> historieTransakci;
    Dynamické pole (vektor) desetinných čísel představující historii vkladů 
    (kladná čísla) a výběrů (záporná čísla).
    Jak pracovat: Přidáváš prvky pomocí .push_back(hodnota), velikost zjišťuješ 
    přes .size().
  - static int pocetUctu;
    Statická proměnná. Není vázána na konkrétní instanci, ale je sdílená všemi 
    účty dohromady. Slouží jako globální čítač žijících objektů v paměti.

* Veřejné rozhraní (public:):
  - Ucet(std::string cisloUctu, std::vector<double> historieTransakci);
    Konstruktor bázové třídy. Inicializuje číslo účtu a historii transakcí.
  - virtual ~Ucet();
    Virtuální destruktor. Zásadní prvek pro polymorfismus! Zaručuje, že při 
    volání delete nad ukazatelem na Ucet* se korektně zavolá destruktor odvozené 
    třídy (BeznyUcet/SporiciUcet) a nedojde k úniku paměti.
  - static int getpocetUctu();
    Statický getter. Vrátí aktuální hodnotu pocetUctu. Lze volat i bez existence 
    jakéhokoliv objektu přes Ucet::getpocetUctu().
  - std::vector<double>& gethistorieTransakci();
    Vrací referenci (&) na vektor transakcí. Znaménko & je klíčové: nevrací kopii, 
    ale přímý přístup k originálu, což umožňuje algoritmům historii modifikovat.
  - void pridejTransakci(double hodnota);
    Přidá jednu transakci na konec vektoru.
  - void pridejTransakce(const std::vector<double>& hodnoty);
    Přidá celý seznam transakcí najednou.
  - virtual void analyzujUcet() const = 0;
    Čistě virtuální metoda (pure virtual). Zápis = 0 dělá z třídy Ucet abstraktní 
    třídu. Třída Ucet nemá pro tuto metodu žádné tělo – přikazuje všem potomkům, 
    že si ji musí sami implementovat.
  - virtual void vypisInfo() const;
    Virtuální metoda pro výpis základních informací. Potomci ji mohou předefinovat 
    (override). Slovo const zaručuje, že metoda nemění stav objektu.


--------------------------------------------------------------------------------
2. Ucet.cpp (Implementace bázové třídy)
--------------------------------------------------------------------------------

[ VÝZNAM SOUBORU ]
Obsahuje samotný kód (logiku) pro metody deklarované v Ucet.h.

[ DETAILNÍ ROZBOR ČÁSTÍ ]

* int Ucet::pocetUctu = 0;
  Inicializace statické proměnné na úrovni souboru. Musí být mimo jakoukoliv funkci.
* Ucet::Ucet(std::string cisloUctu, std::vector<double> historieTransakci)
  Konstruktor. Pomocí inicializačního seznamu nebo přirazení nastaví vnitřní 
  proměnné a inkrementuje počítadlo: pocetUctu++.
* Ucet::~Ucet()
  Destruktor. Při zániku objektu dekrementuje počítadlo: pocetUctu--.
* void Ucet::pridejTransakci(double hodnota)
  Volá historieTransakci.push_back(hodnota);.
* void Ucet::pridejTransakce(const std::vector<double>& hodnoty)
  Prochází předaný vektor cyklem a vkládá hodnoty do historieTransakci.


--------------------------------------------------------------------------------
3. BeznyUcet.h (Hlavičkový soubor běžného účtu)
--------------------------------------------------------------------------------

[ VÝZNAM SOUBORU ]
Definuje třídu BeznyUcet, která dědí z třídy Ucet. Přidává poplatek za vedení 
účtu a přetížení operátorů.

[ DETAILNÍ ROZBOR ČÁSTÍ ]

* class BeznyUcet : public Ucet
  Dědičnost. BeznyUcet přebírá všechny členy a metody z Ucet.
* private: double poplatekZaVedeni;
  Speciální vlastnost běžného účtu. Je private, takže k ní má přístup pouze BeznyUcet.
* virtual void analyzujUcet() const override;
  Implementace povinné čistě virtuální metody z rodiče. Slovo override dává 
  kompilátoru najevo, že přepisujeme metodu z bázové třídy.
* virtual void vypisInfo() const override;
  Přepsání výpisu informací – vypíše data z rodiče + specifický poplatek.

* Přetížení operátorů (Operator Overloading):
  - bool operator==(const BeznyUcet& druhy) const;
    Umožňuje porovnat dva běžné účty pomocí u1 == u2. Vrací true, pokud mají 
    stejný poplatek.
  - BeznyUcet& operator+=(double hodnota);
    Umožňuje přidat transakci zápisem u1 += 500.0;. Vrací reference *this pro 
    možnost řetězení.
  - friend std::ostream& operator<<(std::ostream& os, const BeznyUcet& ucet);
    Klíčové slovo friend dává vnější funkci přístup k privatním členům. 
    Umožňuje přímý výpis do konzole: std::cout << u1;.


--------------------------------------------------------------------------------
4. BeznyUcet.cpp (Implementace běžného účtu)
--------------------------------------------------------------------------------

[ VÝZNAM SOUBORU ]
Obsahuje logiku pro běžný účet, analýzu transakcí a operátory.

[ DETAILNÍ ROZBOR ČÁSTÍ ]

* BeznyUcet::BeznyUcet(...) : Ucet(cisloUctu, historieTransakci), poplatekZaVedeni(...)
  Konstruktor předává číslo účtu a historii k inicializaci rodiči Ucet(...) a sám 
  si uloží poplatekZaVedeni.
* void BeznyUcet::analyzujUcet() const
  Projde historieTransakci a spočítá, kolik transakcí bylo záporných (výběry). 
  Výsledek vypíše do konzole.
* bool BeznyUcet::operator==(const BeznyUcet& druhy) const
  Vrátí výsledek výrazu this->poplatekZaVedeni == druhy.poplatekZaVedeni.
* BeznyUcet& BeznyUcet::operator+=(double hodnota)
  Zavolá pridejTransakci(hodnota); a vrátí *this.


--------------------------------------------------------------------------------
5. SporiciUcet.h (Hlavičkový soubor spořicího účtu)
--------------------------------------------------------------------------------

[ VÝZNAM SOUBORU ]
Definuje třídu SporiciUcet, která rovněž dědí z Ucet, ale místo poplatku spravuje 
úrokovou sazbu.

[ DETAILNÍ ROZBOR ČÁSTÍ ]

* private: double urokovaSazba;
  Specifická vlastnost spořicího účtu (např. 4.5 pro 4.5%).
* virtual void analyzujUcet() const override;
  Povinná implementace analýzy pro spořicí účet.
* double getUrokovaSazba() const;
  Getter pro úrok.


--------------------------------------------------------------------------------
6. SporiciUcet.cpp (Implementace spořicího účtu)
--------------------------------------------------------------------------------

[ VÝZNAM SOUBORU ]
Obsahuje logiku výpočtu průměrného vkladu a výpisu spořicího účtu.

[ DETAILNÍ ROZBOR ČÁSTÍ ]

* void SporiciUcet::analyzujUcet() const
  Projde historieTransakci, sečte všechny kladné hodnoty (vklady), podělí je jejich 
  počtem a vypíše průměrnou výši vkladu.


--------------------------------------------------------------------------------
7. main.cpp (Hlavní spustitelný soubor a Algoritmy)
--------------------------------------------------------------------------------

[ VÝZNAM SOUBORU ]
Vstupní bod programu. Vytváří objekty, demonstruje polymorfismus, testuje 
operátory a spouští algoritmy nad daty.

[ DETAILNÍ ROZBOR ČÁSTÍ ]

* Algoritmy (Nezávislé funkce):
  1. void nejdelsiRadaVkladu(Ucet& nazevUctu)
     Přijímá referenci na Ucet. Prochází historii a hledá nejdelší souvislou 
     sekvenci čísel větších než 0.
     Jak funguje: Má čítač aktualni a nejdelsi. Pokud je číslo > 0, inkrementuje 
     aktualni. Pokud narazí na záporné číslo, aktualni vynuluje.
  2. void odstraneniMalychVyberu(Ucet& nazevUctu)
     Modifikuje historii transakcí. Vymaže všechny výběry v rozsahu od -50.0 do 0.0.
     Jak funguje: Získá referenci na vektor přes gethistorieTransakci(). Prochází 
     ho cyklem a při splnění podmínky zavolá historie.erase(historie.begin() + i). 
     Následně provede i--, aby nepřeskočil následující prvek!

* Funkce main() – Průběh programu:
  1. Alokace na haldě (Heap):
     BeznyUcet* u1 = new BeznyUcet("CZ-1111", {...}, 50.0);
     SporiciUcet* u3 = new SporiciUcet("CZ-3333", {...}, 4.5);
  2. Polymorfní kontejner:
     std::vector<Ucet*> seznamUctu = { u1, u2, u3 };
     Do jednoho vektoru typu Ucet* ukládáme různé potomky.
  3. Polymorfní volání:
     for (size_t i = 0; i < seznamUctu.size(); i++) {
         seznamUctu[i]->vypisInfo();    // Zavolá správnou verzi podle typu!
         seznamUctu[i]->analyzujUcet(); // Zavolá správnou verzi podle typu!
     }
  4. Test Operátorů v izolovaném bloku { ... }:
     Blok {} zaručuje, že lokální proměnné zaniknou dříve, než se zavolá finální 
     kontrola Ucet::getpocetUctu().
  5. Úklid paměti (Dealokace):
     for (size_t i = 0; i < seznamUctu.size(); i++) {
         delete seznamUctu[i]; // Díky virtual ~Ucet() se uvolní vše správně.
     }


================================================================================
NÁVOD K SESTAVENÍ A SPUŠTĚNÍ
================================================================================

1. Kompilace (spojení všech .cpp souborů do jednoho programu):
   g++ -std=c++11 Ucet.cpp BeznyUcet.cpp SporiciUcet.cpp main.cpp -o banka

2. Spuštění:
   * Linux / macOS:   ./banka
   * Windows:         .\banka.exe
