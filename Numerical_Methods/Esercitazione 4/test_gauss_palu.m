% Help:
%Lo script effettua la risoluzione di 10 sistemi lineari di dimensione
%crescente da 100 a 1000 tramite la fattorizzazione PA=LU. In output
%verranno stampati gli errori relativi e i numeri di condizionamento di
%ognuna delle 10 matrici generate.

clc 

%inizializzazione del contatore per il vettore di errori
i = 0;

fprintf("Dimensione\t\tErrore Relativo\t\tNumero di Condizionamento\n")

for n = 100:100:1000 % ciclo for da 100 a 1000 con passo 100
    i = i + 1; % incremento del contatore
    A = rand(n); % creazione di una matrice con elementi pseudocasuali
    x = ones(n, 1); % creazione del vettore colonna di soli 1
    b = A*x; % creazione del vettore b dei termini noti con prodotto tra A e x
    [P, L, U] = gauss_palu(A); % invocazione della funzione gauss_lu passando 
                               % come parametro la matrice, restituirà
                               % la matrice L, U e P
    %risoluzione dei sistemi a cascata per trovare la soluzione x1
    y = L\(P*b);
    x1 = U\y; 
    err = norm(x1-x)/norm(x); % calcolo l'errore relativo della soluzione x1
    cond_num = cond(A); % calcolo il numero di condizionamento
    fprintf("   " + n + "\t\t\t  " + err + "\t\t\t" + cond_num + "\n");
end