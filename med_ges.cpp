#include<iostream>
#include<string.h>

using namespace std;
typedef struct tdate
{
	int jr,ms,an; 
}
tdate;
typedef struct med
{
	string libel;
	float prix_uni;
	int quant_disp;
	tdate d_fab;
	tdate d_exp;
}
med;

typedef struct medicament 
{
	med m;
	struct medicament *next;	
}
medicament;
typedef medicament *listm;


//decalring functions section
/***************/
void consult_med(listm l,string m);//pour consulter 
bool compar_d(tdate d,tdate t);
void exp_med(listm l,tdate d);//med exp
void remaplir_d(tdate &d);
void remplir_med(med &x);//
void Vendre(listm &l, string libl, int nbr);//vender
void afficher_menu();//aff
void delete_listm(listm &l);
void affmts(listm l);
void affstsck(listm l,int n);
bool check_lib(listm l,string s);
void almstock (listm &l, med x);
void ajt_trie(listm &l, med x);
void afflm(listm tmp);
void affoalph(listm l);
void after_case(int &choix);
void intro();
/********************************
**********************************
***********************************
**************main******************
*************************************
**************************************
***************************************/

int main()
{
	system("color a4");
	med x;
	listm l=NULL;
    int choix;
    string m;
    string libl;int nbr;
	tdate d;
	int n;
	afficher_menu();
	do
	{   
		cin>>choix;
		switch (choix)
    	{
    	  	case 1: cout<<"entrer le nom de med";cin>>libl;cout<<"entrer le nombre des meds";cin>>nbr;Vendre(l,libl,nbr);break;
       	 	case 2: remplir_med(x);ajt_trie(l,x); break;
       		case 3: affoalph(l);break;
       		case 4: affmts(l);break;
       		case 5: cout<<"entrer le nom de med ";cin>>m;consult_med(l,m);break;
       		case 6: remaplir_d(d);exp_med(l,d);break;
       		case 7: cout<<"entrer n SVP ";cin>>n;affstsck(l,n);break;
       		case 0: return 0;
             		
    	}
		after_case(choix);
		cout<<choix;
	}while (choix !=0);
	system("pause") ;	
	delete_listm( l);
	return 0;
	
}
//verifier l'existance
bool check_lib(listm l,string s)
{
	bool b=false;
	while(!b&&(l != NULL))
	{
		if(l->m.libel==s)b=true;
		l=l->next;	
	}
	return b;
}
//alementer le stock
void almstock (listm &l, med x)
{
	if((l==NULL)||(!check_lib(l,x.libel)))
	{
		listm p;
		p = new medicament;
		/*****remplir les elem***********/
		p->m.libel=x.libel;
		p->m.prix_uni=x.prix_uni;
		p->m.quant_disp=x.quant_disp;
		/*fab*/
		p->m.d_fab.an=x.d_fab.an;
		p->m.d_fab.jr=x.d_fab.jr;
		p->m.d_fab.ms=x.d_fab.ms;
		/**exp**/
		p->m.d_exp.an=x.d_exp.an;
		p->m.d_exp.jr=x.d_exp.jr;
		p->m.d_exp.ms=x.d_exp.ms;
	    /*/increment/*/
		p->next=l;
		l=p;	
	}
	else
	{
		while((l != NULL))
		{
			if(l->m.libel==x.libel)
			{
				l->m.quant_disp++;
			}	
		}
	}
}
//ajouter des element trie
void ajt_trie(listm &l, med x)
{
	bool b= true;
	while(!b&& l!=NULL)
	{
		if(x.libel<=l->m.libel)
		{
			almstock (l,x);
			b=false;
		}
		else if((l->m.libel<x.libel&&(x.libel<=(l->next->m.libel)))||(l->m.libel<x.libel&&l->next==NULL))
	    {
	    	almstock (l,x);
	    	b=false;
		}
		l=l->next;	
	}
	if(l==NULL)
	{
	 	almstock (l,x);
	}
	
}
//vider toutes la list
void delete_listm(listm &l)
{
	while(l != NULL)
	{
		listm tmp=l->next;
		delete(l);
		l=tmp;		
	}
}
//medicament that are quantity is on risck done
void affstsck(listm l,int n)
{
	for(listm tmp = l ;tmp !=NULL; tmp = tmp->next )
	{
		if ((tmp->m.quant_disp)<n)
		{
			cout<<tmp->m.libel<<" est en risque";
		}
	}
}

//afficher le montant total  done
void affmts(listm l)
{
	int m=0;
	for(listm tmp = l ;tmp !=NULL; tmp = tmp->next )
	{
		m=m+((tmp->m.prix_uni)*(tmp->m.quant_disp));
	}
	cout<<"Le monotant total est: "<<m;
}

//menu
void afficher_menu()
{
    system("cls");
    cout<<"\n\n- Choisir une option dans le menu suivant:";
    cout<<"\n\t + Vendre un m�dicament.                     <1>:";
    cout<<"\n\t + Alimenter le stock                       <2>:";
    cout<<"\n\t + Afficher la liste de medicamente selon l'ordre alphabetique \n\t  de leurs libelles.     <3>:";
    cout<<"\n\t + Afficher le montant total du stock.     <4>:";
	cout<<"\n\t + Consulter le prix et la quantite disponible pour un m�dicament \n\t       <5>:"; 
	cout<<"\n\t + Afficher la liste des medicaments expirant avant \n\t  une date donn� d.     <6>:";
	cout<<"\n\t + Afficher la liste des medicaments dont leurs stocks est en risque \n\t  (inferieur � une quantite donnee).      <7>:";
	cout<<"\n\t + pour quiter                                                  <0>:";
    cout<<"\n\n- Entrez votre choix:";
}

//vender
void Vendre(listm &l, string libl, int nbr)
{
	bool psbl=false;
	if(l!=NULL)
	{
		listm p,q;
		p=l;q=l;
		while((q!=NULL)&&(q->m.libel!=libl))
		{
			p=q;q=q->next;
		}
		if(q->m.quant_disp>=nbr)
		{
			psbl=true;
			q->m.quant_disp= q->m.quant_disp - nbr;
			if(q->m.quant_disp==0)
			{
				if(p=q)
				{
					l=p->next;delete(p);
				}
				else
				{
					p->next=q->next;delete(q);
				}
			}
			
		}
	}
	if(!psbl)
	{
		cout<<"il est impossible de vender "<<libl;   	
	} 
}
//rmplir date
void remaplir_d(tdate &d)
{
	cout<<"jour ";cin>>d.jr;
	cout<<"mois ";cin>>d.ms;
	cout<<"annee ";cin>>d.an;
}
void remplir_med(med &x)
{
	
	cout<<" name of your medicament:";
	cin>>x.libel;
	cout<<" saiser la quantite ";
	cin>>x.quant_disp;
	cout<<" price";
	cin>>x.prix_uni;
	cout<<"date de fabrication \n";
	remaplir_d(x.d_fab);
	cout<<"date d'expiration \n";
	remaplir_d(x.d_exp);
}

//l'expeeration d'un medicament
void exp_med(listm l,tdate d)
{
	for(listm tmp = l ;tmp !=NULL; tmp = tmp->next )
	{
		if(compar_d(d,tmp->m.d_exp))
		{
			cout<<tmp->m.libel<<"expirant avant la date \n"<<"j: "<<d.jr<<" m: "<<d.ms<<" an: "<<d.an;
		}
	}
}
//date comparaison
bool compar_d(tdate d,tdate t)
{
	if(d.an>t.an)return true;
	else
	   if(d.an<t.an)return false;
	   else
	     if(d.ms>t.ms) return true;
	     else
	       if(d.ms<t.ms) return false;
	       else
	         if(d.jr>t.jr) return true;
	         else
	         return false;
}

//consult the price and quantity of med
void consult_med(listm l,string m)
{
	bool b=false;
	while(!b&&(l != NULL))
	{
		
		if(l->m.libel==m)
		{
			cout<<"le prix: "<<l->m.prix_uni<<" DZD  la quantit�: "<<l->m.quant_disp;
			b=true;
		}
		l=l->next;
		
	}
	if(b==false)
	{
		cout<<"le medicament "<<m<<" n'existe pas";
	}
}
void after_case(int &choix)
{
	cout<<"\nContinuer ou Non ?*------> ""c"" pour Continuer\t***\t""0"" pour Non Continuer<------*\n";
	string b;
	cin>>b;
	if(b=="c"||"C")
	{
		afficher_menu();
	}
	if(b=="0")
	{
		choix=0;
	}
}

void afflm(listm tmp)
{
	cout<<tmp->m.libel<<" *|||* "<<tmp->m.prix_uni<<" *|||* "<<tmp->m.quant_disp;
	cout<<"\n"<<"~>"<<"fab: "<<tmp->m.d_fab.jr<<"/"<<tmp->m.d_fab.ms<<"/"<<tmp->m.d_fab.an;
	cout<<"\n"<<"~>"<<"exp: "<<tmp->m.d_exp.jr<<"/"<<tmp->m.d_exp.ms<<"/"<<tmp->m.d_exp.an<<"\n";
}


void affoalph(listm l)
{
	cout<<"libelle nom *|||* prix unitaire *|||* quantite disponible\n";
	for(listm tmp = l ;tmp !=NULL; tmp = tmp->next )
	{
		afflm(tmp);
	}
}
	
	

