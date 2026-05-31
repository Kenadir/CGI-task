## Opis projektu

Program symuluje prosty system bankowy w konsoli. Umożliwia tworzenie kont oraz wykonywanie podstawowych operacji finansowych takich jak wpłaty, wypłaty oraz wyświetlanie informacji o koncie.

Projekt został napisany w C++ z wykorzystaniem programowania obiektowego oraz dynamicznego zarządzania pamięcią (std::unique_ptr).

---

## Funkcjonalności

- Tworzenie konta bankowego
- Wpłata środków na konto
- Wypłata środków z konta (z kontrolą salda)
- Wyświetlanie danych konta (ID, właściciel, saldo)
- Wyszukiwanie konta po ID lub nazwie
- Walidacja danych wejściowych użytkownika
- Obsługa błędnych danych (np. litery zamiast liczb)

---

## Struktura projektu
include/ 

    Classes.h 
  
    BankUI.h

src/ 

    Classes.cpp

    BankUI.cpp
  
    CGI-task.cpp 
---

## Struktura klas 

### Account 
Odpowiada za pojedyncze konto bankowe.
Przechowuje:
-ID konta 
-właściciela
-saldo

Obsługuje operacje:
- wpłata (`deposit`)
- wypłata (`withdraw`)
- wyświetlanie danych (`display_Info`)

---

### Bank
Zarządza listą kont.
Odpowiada za:
- tworzenie kont
- wyszukiwanie kont po ID i nazwie
- przechowywanie kont w `std::vector<std::unique_ptr<Account>>`

---

### BankUI
Interfejs konsolowy użytkownika.
Obsługuje:
- menu
- komunikację z użytkownikiem
- przekazywanie operacji do Bank

---

## Decyzje projektowe 
- Zastosowano std::unique_ptr do zarządzania pamięcią (RAII)
- Oddzielenie logiki biznesowej (Bank, Account) od UI (BankUI)
- Brak trwałej bazy danych – dane istnieją tylko w runtime
- Zastosowano std::unique_ptr (RAII) eliminując potrzebę ręcznego zarządzania pamięcią
---

## Obsługa błędów

- Walidacja wejścia użytkownika (liczby/tekst)
- Ochrona przed wypłatą większą niż saldo
- Obsługa błędnych ID kont

---

## Zastosowane technologie

-C++

-STL (vector, memory, algorithm)

- std::unique_ptr (RAII) 

-Obsługa wejścia i wyjścia w konsoli 

---

## Uruchomienie

### Visual Studio:
1.Otwórz plik '.sln'

2.Zbuduj projekt(Build)

3.Uruchom (Ctrl + F5)

### Linux i inne:
Projekt zawiera Makefile umożliwiający kompilację programu:

- `make` – buduje projekt
- `make run` – uruchamia program
- `make clean` – usuwa pliki tymczasowe

### Wymagania

- g++ (C++17)
- Make (Linux / WSL / MSYS2 / Git Bash)

### Uwaga

Projekt był tworzony z myślą o systemie Windows, dlatego używa `system("cls")` do czyszczenia konsoli.
Dla systemów Linux/macOS wymagane jest zastąpienie tej funkcji odpowiednikiem `clear`.

---

## Założenia projektu 

-Program działa w konsoli 

-Każde konto posiada numer, właściciela i saldo

-Dane przechowywane są wyłącznie podczas działania programu

---

## Planowane Ulepszenia

-Dodanie klasy enum aby switche były bardziej zrozumiałe 

-Refaktoryzacja UI

-GUI(np. Qt)

-Lepsza walidacja wejścia użytkownika

-Zmiana system("cls") lub jego abstrakcja

---

## Przykładowe działanie
```
======Menu======

Wybierz jedna z opcji wpisujac na wejscie przyporzadkowana liczbe:
1: Stworz konto
2: Wejdz na dane konto
3: Wyjscie
>1

Prosze wprowadzic nazwe uzytkownika:
> User

Prosze wprowadzic saldo uzytkownika(opcjonalnie, mozna wpisac 0):
> 200

Owner: User
Saldo: 200
ID:    0
Konto zostalo utworzone.
Nacisnij enter...

```
---

## Komendy linii poleceń 

### sklonowanie repozytorium
git clone <url-repozytorium>

### sprawdzenie statusu plików
git status

### dodanie zmian do commita
git add .

### utworzenie commita
git commit -m "dodanie systemu UI banku"

### wysłanie zmian na GitHuba
git push origin main

### przejście na istniejący branch
git checkout user-interface lub git switch user-interface

### tworzenie nowego brancha i przejście na niego 
git checkout -b user-interface lub git switch -c user-interface

### historia commitów
git log     

### lista branchy
git branch   

### przejście na główną gałąź
git checkout main  lub git switch main

### scalanie zmian 
git merge user-interface

---

## Autor 

Projekt wykonany jako zadanie rekrutacyjne (CGI-staż:programista C++)

---
