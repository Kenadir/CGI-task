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
  
---

## Zastosowane technologie

-C++

-STL (vector, memory, algorithm)

-std::unique_ptr (RAII)

-Obsługa wejścia i wyjścia w konsoli 

---

## Uruchomienie

### Visual Studio:
1.Otwórz plik '.sln'

2.Zbuduj projekt(Build)

3.Uruchom (Ctrl + F5)

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
>
```
## Autor 

Projekt wykonany jako zadanie rekrutacyjne (CGI-staż:programista C++)

---
