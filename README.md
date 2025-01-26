# So_long

**so_long** è un progetto che consiste nello sviluppo di un piccolo videogioco in 2D utilizzando la libreria **MiniLibX**. Lo scopo del progetto è creare un'applicazione grafica che permetta a un giocatore di navigare in un labirinto, raccogliere oggetti e raggiungere l'uscita.

---

## 📜 Descrizione

Il gioco si basa su una semplice mappa rettangolare che deve rispettare specifici requisiti. Il giocatore può muoversi in quattro direzioni (alto, basso, destra, sinistra) e deve raccogliere tutti gli oggetti presenti sulla mappa prima di uscire dal labirinto.

### Obiettivi principali:
- Implementare un'applicazione grafica utilizzando **MiniLibX**.
- Gestire eventi come il movimento del giocatore e la chiusura della finestra.
- Validare la mappa, assicurandosi che rispetti i requisiti richiesti.
- Mostrare il numero di mosse effettuate dal giocatore.

---

## 🛠️ Requisiti

Per compilare ed eseguire il progetto, assicurati di avere:
- **MiniLibX** installata.
- Un sistema operativo compatibile con **X11** (per Linux) o **macOS**.
- GCC o un altro compilatore compatibile con il progetto.

---

## ⚙️ Compilazione

make
Dopo la compilazione, verrà generato un eseguibile chiamato so_long.
## 🚀 Esecuzione
Avvia il gioco Esegui il gioco specificando una mappa valida come argomento:

^ ./so_long maps/example.ber
### Navigazione nel gioco

Usa i tasti freccia o i tasti WASD per muovere il personaggio.
Raccogli tutti gli oggetti (C) presenti sulla mappa.
Raggiungi l'uscita (E) per vincere.

## 🗺️ Specifiche della mappa

La mappa deve essere un file `.ber` e deve rispettare i seguenti requisiti:

- Deve essere **rettangolare**.
- Deve contenere i seguenti elementi:
  - `1`: Muri.
  - `0`: Spazi vuoti.
  - `P`: Posizione iniziale del giocatore (**unica**).
  - `C`: Collezionabili (**almeno uno**).
  - `E`: Uscita (**unica**).
- La mappa deve essere **completamente chiusa** (circondata da `1`).

**Esempio di mappa valida:**
```
111111
100C01
10P0E1
111111
```

---

## 🔧 Debug e Test

### Validare la mappa
- Per verificare che la mappa sia valida, usa strumenti come un editor di testo per controllare:
  - La presenza dei caratteri richiesti.
  - La chiusura dei bordi della mappa.

### Gestione degli errori
Il programma deve mostrare un messaggio di errore e uscire se:
- La mappa **non è valida**.
- I file forniti **non sono corretti**.
