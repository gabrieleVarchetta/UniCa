% Help:
%La funzione dati in input le ascisse di interpolazione x, le ordinate di
%interpolazione y e le ascisse per disegnare il grafico xx, restituisce il
%valore del polinomio interpolante calcolato nelle ascisse date. Il
%polinomio interpolante viene calcolato usando i polinomi di Lagrange.

function yy = lagrint(x,y,xx)

%con questa particolare sintassi stiamo trasformando i due vettori riga x e
%y in due vettori colonna
x = x(:);
y = y(:);

%salvataggio della dimensione del vettore delle ascisse
n = size(x,1);

%inizializzazione di un vettore che conterrà i denominatori dei polinomi
%caratteristici
den = zeros(n,1); 

%Lj(x) = ((x-x1)/(xj-x1))*((x-x2)/(xj-x2))*...*((x-xn)/(xj-xn))
%p(x) = y(1)*L0(x) + y(2)*L1(x) + ... + y(n)*Ln-1(x)

%il seguente ciclo va a calcolare tutti i denominatori dei polinomi
%caratteristici e li salva dentro il vettore precedentemente creato
for j = 1:n
    den(j) = prod(x(j) - x([1:j-1,j+1:end]));
end

%salvataggio della dimensione del vettore delle ascisse in cui disegnare il
%grafico
m = size(xx,1); 

% inizializzazione di un vettore grande quanto xx
yy = zeros(m,1); 

%il seguente ciclo trova i numeratori del polinomio caratteristico di
%Lagrange e successivamente calcola l'intero polinomio
for i=1:m
    num = prod(xx(i)-x)./(xx(i)-x); 
    L = num./den; %calcolo dei polinomi L0, L1, ..., Lm
    yy(i) = y'*L; %y(1)*L0(x) + y(2)*L1(x) + ... + y(n)*Ln-1(x)
end

%costruisce il grafico della funzione, 'or' indica i cerchi rossi che sono
%i punti da interpolare e xx,yy sono i punti in cui passa la funzione,
%uniti da una linea blu
plot(x,y,'or',xx,yy,'b-')

%stampa una legenda nel grafico
legend('dati da interpolare','polinomio interpolante')




