function [x,k, rho] = jacobi(A,b,tol,kmax,x0)

% Help:
% questa funzione calcola l'approssimazione di x tramite l'algoritmo di
% Jacobi
% gli input sono la matrice, vettore termini noti, tau (tolleranza), numero
% massimo di iterazioni e vettore iniziale
% gli output sono la soluzione x, numero di iterazioni e raggio spettrale

%Creazione della matrice diagonale
D = diag(diag(A)); 

%Creazione della matrice triangolare inferiore scendendo di una diagonale e
%invertendo il segno
E = -tril(A,-1); 

%Creazione della matrice triangolare superiore salendo di una diagonale e
%invertendo il segno
F = -triu(A,1); 

% Creazione della matrice di Jacobi
Bj = D\(E+F); 

%Creazione del vettore f da usare per le iterazioni
f = D\b; 

%Calcolo del raggio spettrale della matrice di Jacobi per controllare
%la convergenza
rho = max(abs(eig(Bj))); 

% Prima iterazione
x_old = x0;
x_new = Bj*x_old + f;

% Inizializzazione del contatore per le iterazioni
k = 1; 

% La prima condizione del while rappresenta il criterio di arresto di Cauchy,
% si considera lo scarto relativo tra due iterazioni successive fissando una
% certa tolleranza tol, mentre la seconda condizione rappresenta il numero
% massimo di iterazioni che, nel caso in cui l'algoritmo non converga,
% non deve essere superato
while (norm(x_new-x_old)>tol*norm(x_old)) && (k<kmax) 
    k = k+1; % incremento del contatore
    x_old = x_new; % salvataggio della nuova soluzione in x_old
    x_new = Bj*x_old + f; % calcolo l'iterazione successiva
end

%Se il limite massimo di iterazioni è stato superato, stampo un messaggio
%di errore
if (k>=kmax)
    warning('Raggiunto il numero massimo di iterazioni')
end

% Se tutto è andato a buon fine, salvo nella x l'ultima iterazione
x = x_new;



