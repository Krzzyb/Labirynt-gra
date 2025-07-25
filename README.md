# Labirynt-gra

Labirynt-gra to konsolowa gra w C++, w której gracz porusza się po losowo generowanym labiryncie, unikając min, zbierając niespodzianki i korzystając ze szpitali. Gra posiada system zapisu i wczytywania stanu gry oraz ustawień.

## Funkcje gry

- **Losowe generowanie labiryntu** – funkcja [`randPath`](Labirynt.cpp) tworzy ścieżkę od startu do mety.
- **Losowanie elementów** – funkcja [`randItems`](Labirynt.cpp) rozmieszcza miny, niespodzianki i szpitale.
- **Wyposażenie gracza** – gracz może zdobyć wykrywacz metalu lub sonar, które pomagają w rozgrywce ([`randEquip`](Labirynt.cpp)).
- **System żyć** – każde wejście na minę odbiera jedno życie ([`livescounter`](Labirynt.cpp)).
- **Zapisywanie i wczytywanie gry** – funkcje [`saveGame`](Labirynt.cpp) oraz [`loadGame`](Labirynt.cpp) pozwalają zachować postęp.
- **Opcje gry** – możliwość wyboru poziomu trudności oraz ustawień graficznych ([`mainOptions`](Labirynt.cpp)).
- **Menu gry** – obsługa menu głównego i pauzy ([`startMenu`](Labirynt.cpp), [`menu`](Labirynt.cpp)).

## Sterowanie

- Strzałki – poruszanie się po planszy
- ESC – menu pauzy
- ENTER – wybór opcji w menu

## Uruchomienie

1. Skompiluj plik [Labirynt.cpp](Labirynt.cpp) za pomocą kompilatora C++ (np. MinGW lub Visual Studio).
2. Uruchom wygenerowany plik wykonywalny (`Labirynt.exe`).

## Wymagania

- System Windows (gra korzysta z funkcji konsoli Windows)
- Kompilator C++ zgodny z WinAPI

## Pliki projektu

- [Labirynt.cpp](Labirynt.cpp) – główny plik źródłowy gry
- savingGameTest.cpp – testy zapisu/wczytywania gry
- Test.cpp – testy konsoli i funkcji pomocniczych

## Autor

Projekt szkolny – gra konsolowa Labirynt