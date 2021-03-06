Bomberman
=============

## Ovládání

Hru ovládá až několik hráčů za pomocí konzole. Hráče lze ale nastavit i jako umělou inteligenci ovládanou počítačem

## Implementace

jedná se o variaci na klasickou hru "Bomberman" viz.
https://en.wikipedia.org/wiki/Bomberman

Po spuštění hry se uživateli otevře command line s dostupnými příkazy, 
za pomocí kterých může hráč vybrat jednu z úrovní. Při načítání úrovně si hráč postupně vybírá u jednotlivých bombermanů, jestli jsou ovládané hráčem nebo počítačem a případně jejich jména.

Hráč se pohybuje na obdelníkové mřížce vyplněné bloky. Může pokládat na zem bombu, která po krátkém čase vybuchne a odpálí do vzduchu vše v blízkosti.
Některé bloky jsou tímto způsobem zničitelné, ale ne všechny. Po mapě se dále pohybují počítačem simulovaní duchové, 
kteří hráče vyřadí ze hry svým dotekem. To se týká jak hráčem ovládaného bombera, tak i počítačem simulovaného.

Na mapě se objevují vylepšení. Ze základu jsou některé z nich objevují na předem určených místech v úrovni.
Vylepšení se liší vzhledem, svými efekty ovlivňují buď atributy postav jako je například jejich maska, nebo vlastnosti jejich bomb.

Cílem hry je odpálit do vzduchu co nejvíce duchů, počítačem ovládaných robotů a případně protihráčů. 
V průběhu hry se počítá skóre bomberům, kteří jsou ovládáni hráči. To se po ukončení úrovně se toto skóre ukládá v případě, že je vyšší než předchozí skóre pro tuto úroveň.
Ve chvíli, kdy v úrovni zbývá poslední hráč a žádní duchové či roboti, přeživší hráč vyhrává hru. 
Jeho skóre se porovná se současným nejvyšším a případně se uloží. Následně se zavře okno hry a hra končí
