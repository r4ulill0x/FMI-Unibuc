% rezolvari Prolog teme colective 8-16 Grupa 1 Informatica ID 2023-2024

:- [lab6lmc1].

/* Predicatul imagine(+Functie;+SubmultimeADomeniuluiFunctiei;-Imagine), care
determina in al treilea argument imaginea multimii data de lista de constante din
al doilea argument prin functia data de primul argument ca relatie functionala
totala, deci ca lista de perechi de constante*/

imagine(_,[],[]).
imagine(F,[H|T],[FH|U]) :- member((H,FH),F), imagine(F,T,U).

/*Predicatul preimagine(+Functie;+SubmultimeACodomeniuluiFunctiei;-Preimagine), care
determina in al treilea argument preimaginea multimii data de lista de constante din
al doilea argument prin functia data de primul argument ca relatie functionala totala,
deci ca lista de perechi de constante*/

preimagine(_,[],[]).
preimagine(F,[FH|T],[H|U]) :- member((H,FH),F), preimagine(F,T,U).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% relatii functionale (partiale) de la A la B
% functionala(+Relatie), care determina daca o lista Relatie de perechi de constante este functie partiala:

functionala(R) :- not((member((X,Y),R), member((X,Z),R), Y\=Z)).

/* relfunctionala(Relatie;+MultimeDomeniu;+MultimeCodomeniu), care genereaza in argumentul Relatie fiecare 
functie partiala de la multimea MultimeDomeniu la multimea MultimeCodomeniu: */

relfunctionala(R,A,B) :- relbin(R,A,B), functionala(R).

/* relatiifunctionale(+MultimeDomeniu;+MultimeCodomeniu;MultimeRelatii), care genereaza in argumentul 
MultimeRelatii multimea functiilor partiale de la multimea MultimeDomeniu la multimea MultimeCodomeniu: */

relatiifunctionale(A,B,MultRelFunctionale) :- setof(R, relfunctionala(R,A,B), MultRelFunctionale).


% relatii totale de la A la B
/* totalape(+Relatie;+MultimeDomeniu), care determina daca o relatie binara Relatie de la o multime 
MultimeDomeniu la o alta multime este totala: */

totalape(R,A) :- not((member(X,A), not(member((X,_),R)))).

/* reltotalape(Relatie;+MultimeDomeniu;+MultimeCodomeniu), care genereaza in argumentul Relatie fiecare 
relatie binara totala de la multimea MultimeDomeniu la multimea MultimeCodomeniu: */

reltotalape(R,A,B) :- relbin(R,A,B), totalape(R,A).

/* relatiitotalepe(+MultimeDomeniu;+MultimeCodomeniu;MultimeRelatii), care genereaza in argumentul MultimeRelatii 
multimea relatiilor binare totale de la multimea MultimeDomeniu la multimea MultimeCodomeniu: */

relatiitotalepe(A,B,MultRelTotalePe) :- setof(R, reltotalape(R,A,B), MultRelTotalePe).


% relatii complete pe multimea A
% completa(+Relatie;+Multime), care determina daca o relatie binara Relatie pe o multime Multime este completa:
completa(R,A) :- not((member(X,A), member(Y,A), not(member((X,Y),R)), not(member((Y,X),R)))).

% relcompleta(Relatie;+Multime), care genereaza in argumentul Relatie fiecare relatie binara completa pe multimea Multime:

relcompleta(R,A) :- relbin(R,A,A), completa(R,A).

/* relatiicomplete(+Multime;􀀀MultimeRelatii), care genereaza in argumentul MultimeRelatii multimea relatiilor 
binare complete pe multimea Multime */

relatiicomplete(A,MultRelComplete) :- setof(R, relcompleta(R,A), MultRelComplete).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* submultimilinord(+Multime;+Ordine;MultimeLanturi), care determina in al treilea argument, pentru un poset 
(Multime; Ordine) (subinteles: cu multimea suport Multime si relatia de ordine Ordine), multimea submultimilor 
multimii Multime care sunt total ordonate in posetul (Multime; Ordine), adica raportat la ordinea indusa pe acele 
submultimi de ordinea Ordine de pe Multime: */

submultimilinord(Multime,Ordine,MultimeLanturi):-setof(S,(sublista(S,Multime),totala(Ordine,S)),MultimeLanturi).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* O proprietate a relatiilor de ordine (pe o multime arbitrara) spune ca orice relatie de ordine pe o 
multime se poate completa la o relatie de ordine totala pe acea multime. In plus, orice submultime a unei 
relatii de succesiune (acoperire) pe o multime este o relatie de succesiune pe acea multime. Asadar multimea 
relatiilor de succesiune pe o multime este multimea submultimilor relatiilor de succesiune asociate ordinilor 
totale pe acea multime. Relatiile de ordine totale (liniare) pe o multime finita sunt date de permutarile
acelei multimi, astfel: daca multimea respectiva este data de o lista Prolog fara duplicate M, atunci orice 
permutare a listei M corespunde relatiei de ordine totale asociate relatiei de succesiune */

/* predicatul ordinepe(+M,-Ord) care genereaza submultimile care sunt preordini (si implicit ordini, intrucat 
submultimile unei relatii binare antisimetrice sunt antisimetrice) ale relatiilor de ordine totale pe multimea M, 
asociate relatiilor de succesiune corespunzatoare fiecareia dintre cele n! permutari ale multimii M 
(i.e. bijectii de la M la M) */

ordinepe(M,Ord) :- permutare(M,RelOrdTot), succlant(RelOrdTot,SuccOrdTot), 
		orddinsucc(SuccOrdTot, M, OrdSucc), sublista(Subliste,OrdSucc), 
		ord(Subliste,M), sort(Subliste,Ord).	

/* varianta pentru predicatul ordinepe, care genereaza inchiderile reflexive ale submultimilor care sunt relatii 
tranzitive (si implicit ordini stricte) ale relatiilor de ordine stricta asociate ordinilor totale pe multimea M, 
asadar relatiilor de succesiune corespunzatorare permutarilor multimii M */

ordinepe1(M,Ord) :- permutare(M,P), succlant(P,SuccLant), 
	ordstrdinsucc(SuccLant,OrdStrLant), sublista(OrdStr,OrdStrLant), 
	tranz(OrdStr), inchrefl(OrdStr,M,O), sort(O,Ord).

/* ordinile(+Multime;Ordinile) care determina multimea (i.e. lista fara duplicate) Ordinile a tuturor relatiilor 
de ordine pe multimea (finita) Multime */
ordinile([], [[]]) :- !.
ordinile(M, Ordinile) :- setof(Ord,ordinepe(M,Ord),Ordinile). 

% varianta:
ordinile1([], [[]]) :- !.
ordinile1(M, Ordinile) :- setof(Ord,ordinepe1(M,Ord),Ordinile).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* predicat latdistrib(+Multime;+Ordine) care determina daca posetul (Multime; Ordine) este latice Ore 
distributiva: */
% se testeaza urmatoare lege de distributivitate: x^(yVz) = (x^y)V(x^z)

latdistrib(L,Ord) :- not((member(X,L), member(Y,L), member(Z,L), sup(YsauZ,[Y,Z],L,Ord), 
		inf(MembrStg,[X,YsauZ],L,Ord), inf(XsiY,[X,Y],L,Ord), inf(XsiZ,[X,Z],L,Ord), 
		sup(MembrDr,[XsiY,XsiZ],L,Ord), MembrStg\=MembrDr)).

/*interogare:
?- poslat3(M,Ord),latdistrib(M,Ord).
false.

?- poslat4(M,Ord),latdistrib(M,Ord).
M = [0, a, 1],
Ord = [(0, 0), (a, a), (1, 1), (0, a), (a, 1), (0, 1)].

?- latdistrib([0,a,1],[(0,0),(a,a),(1,1),(0,a),(a,1),(0,1)]).
true.
*/

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* predicat algBoole(+Multime;+Ordine) care determina daca posetul (Multime; Ordine) 
este laticea Ore subiacenta unei algebre Boole: */

algBoole(M, Ord):- not((not(latdistrib(M, Ord)); not(latmargcomplementata(M,Ord)))).

