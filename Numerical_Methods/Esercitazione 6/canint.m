% Help:
%La funzione dati in input le ascisse di interpolazione x, le ordinate di
%interpolazione y e le ascisse per disegnare il grafico xx, restituisce il
%valore del polinomio interpolante calcolato nelle ascisse date. Il
%polinomio interpolante viene calcolato usando la base canonica.

function yy = canint(x,y,xx)

%con questa particolare sintassi stiamo trasformando i due vettori riga x e
%y in due vettori colonna
x = x(:);
y = y(:);

%salvataggio della dimensione del vettore delle ascisse
n = size(x,1);

%inizializzazione di una matrice che conterrà gli elementi della base
%canonica
X = zeros(n);

%il seguente ciclo va a costruire la matrice di Vandermonde, ad ogni ciclo
%vengono inseriti gli elementi
for j = 1:n
    X(:,j) = x.^(j-1);
end

%risoluzione del sistema lineare Xa = y
a = X\y;

%salvataggio della dimensione del vettore delle ascisse in cui disegnare il
%grafico
m = size(xx,1); 

% inizializzazione di un vettore grande quanto xx
yy = zeros(m,1); 

%p = a0*x^0 + a1*x^1 + ... + an*x^n in teoria
%p = a1*x^0 + a2*x^1 + ... + a(n)*x^(n-1) su Matlab

%il seguente ciclo va a costruire il polinomio interpolante nella forma 
% p = a0*x^0 + a1*x^1 + ... + an*x^n
for j = 1:m
    s = 0;
    for i = 1:n %calcola uno ad uno i componenti del polinomio
        s = s + a(i)*(xx(j)^(i-1)); % a1*x^0 + a2*x^1 + ... + a(n)*x^(n-1)
    end
    yy(j) = s;
end

%costruisce il grafico della funzione, 'or' indica i cerchi rossi che sono
%i punti da interpolare e xx,yy sono i punti in cui passa la funzione,
%uniti da una linea blu
plot(x,y,'or',xx,yy,'b-')

%stampa una legenda nel grafico
legend('dati da interpolare','polinomio interpolante')








