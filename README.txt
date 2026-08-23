===========================================================================
                 ŠIFROVANÝ DIGITÁLNÍ TREZOR (v1.0)
===========================================================================
Autor: Vojtěch
Platforma: C++17, OpenSSL, SQLite3
Určení: Semestrální projekt (Vysoká škola / UNOB)

---------------------------------------------------------------------------
1. POPIS PROJEKTU
---------------------------------------------------------------------------
Šifrovaný digitální trezor je konzolová aplikace pro bezpečnou správu citlivých 
přihlašovacích údajů (hesla, uživatelská jména, poznámky k účtům). 

Aplikace je navržena podle bezpečnostního principu "Zero Knowledge". To 
znamená, že program nikdy nikam neukládá hlavní (Master) heslo uživatele v 
otevřeném textu. Veškeré šifrování a dešifrování probíhá lokálně přímo 
v operační paměti (RAM) za běhu programu. Pokud by útočník fyzicky získal 
soubor databáze (trezor.db), bez znalosti Master hesla z něj nedokáže 
přečíst žádná data.

---------------------------------------------------------------------------
2. HLAVNÍ FUNKCE (MENU)
---------------------------------------------------------------------------
1. Zobrazit všechny záznamy (Dešifrovat za běhu z SQLite a vypsat)
2. Přidat nový záznam (Zašifrovat vstupy a uložit do databáze)
3. Vygenerovat silné náhodné heslo (Generátor s vysokou entropií)
4. Smazat záznam podle ID (Bezpečné odstranění z databáze)
5. Zamknout trezor a odejít (Bezpečné promazání RAM a ukončení)

---------------------------------------------------------------------------
3. BEZPEČNOSTNÍ ARCHITEKTURA (Kryptografické trumfy)
---------------------------------------------------------------------------
* PBKDF2 (SHA-256): Slouží k bezpečnému odvození šifrovacího klíče z Master 
  hesla s využitím unikátní 16bajtové soli (Salt) a 100 000 iterací. 
  Brání útokům typu brute-force a Rainbow Tables.

* AES-256-GCM: Moderní symetrické šifrování v režimu GCM (Galois/Counter Mode). 
  Kromě důvěrnosti dat zajišťuje také integritu (autentizaci) pomocí 16bajtového 
  autorizačního tagu. Jakýkoliv pokus o manipulaci se zašifrovanými daty 
  v databázi způsobí selhání dešifrování.

* Ochrana RAM (Anti-forenzní ochrana): Citlivá data (plaintext hesla, 
  šifrovací klíče) jsou v paměti RAM uchovávána pouze po nezbytně nutnou dobu 
  a před uvolněním paměti jsou okamžitě přepsána nulami pomocí funkce 
  OPENSSL_cleanse (včasná destrukce stop v RAM).

* Imunita vůči SQL Injection: Komunikace s SQLite3 nepoužívá prosté spojování 
  řetězců, nýbrž nativní Prepared Statements (parametrizované dotazy), což 
  zcela eliminuje možnost zneužití vstupních polí k SQL injekci.

---------------------------------------------------------------------------
4. STRUKTURA SOUBORŮ V PROJEKTU
---------------------------------------------------------------------------
* main.cpp
  - Řídicí bod programu. Zajišťuje uživatelské rozhraní (CLI menu), zpracování 
    vstupů a logiku aplikace.

* CryptoManager.h / .cpp
  - Kryptografické jádro aplikace. Zapouzdřuje funkce knihovny OpenSSL pro 
    šifrování/dešifrování (AES-256-GCM), generování náhodných bajtů, 
    odvozování klíčů (PBKDF2) a bezpečné čištění paměti.

* DatabaseManager.h / .cpp
  - Modul pro správu datového úložiště. Zajišťuje SQL operace s databází SQLite3, 
    inicializuje tabulky a bezpečně zapisuje/čte šifrované záznamy.

* PasswordGenerator.h / .cpp
  - Generátor silných náhodných hesel na základě zadané délky. Využívá 
    kryptograficky bezpečný zdroj pseudonáhodných čísel s vysokou entropií.

* CMakeLists.txt
  - Konfigurační soubor pro CMake. Definuje způsob sestavení projektu, standard 
    C++17 a linkování externích knihoven (OpenSSL a SQLite3).

* trezor.db
  - SQLite databázový soubor (vytvoří se automaticky). Slouží jako bezpečné 
    úložiště zašifrovaných dat.

---------------------------------------------------------------------------
5. JAK PROGRAM RESETOVAT (PŘÍPRAVA NA PREZENTACI)
---------------------------------------------------------------------------
Pokud chcete program uvést do naprosto čistého stavu pro účely prezentace 
nebo testování:
1. Ukončete program (volba 5).
2. Smažte soubor "trezor.db" ve složce s programem.
3. Při dalším spuštění vás program automaticky vyzve k vytvoření nového 
    Master hesla (první spuštění / registrace).

---------------------------------------------------------------------------
6. POŽADAVKY PRO SESTAVENÍ
---------------------------------------------------------------------------
- Překladač s podporou C++17 (MSVC, GCC, Clang)
- CMake (verze 3.10 nebo novější)
- OpenSSL (verze 1.1.1 nebo 3.x)
- SQLite3
===========================================================================