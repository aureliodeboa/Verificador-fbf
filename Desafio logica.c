//Programa que  diz se a formula e bem formada ou nao 
/* o programa deve ler  a formula e assegurar se ela  bem formada ou nao*/
/*DICIONARIO DE SIMBOLOS

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void afabeto()
{
    printf("\n \t ========================ALFABETO============================ \n");
    printf("\t SIMBOLOS DE PONTUACAO:\n\n");
    printf("\t  ( \n\n");
     printf("\t ) \n\n");
    printf("\t CONECTIVOS: \n\n");
    printf("\t NAO  : ~  \n");
    printf("\t OU   : v  \n");
    printf("\t E    : &  \n");
    printf("\t ->   : >  \n");
    printf("\t <->  : =  \n");
    printf("\t SIMBOLOS DE VERDADE:\n\n");
    printf("\t True  : 1 \n ");
    printf("\t False : 0 \n ");
    printf("\t SIMBOLOS PROPOSICIONAIS:\n\n");
    printf("\t P,Q,R,S,X,U,V. \n");
    printf("\n\t=================================================================\n");
    printf("\n Digite Formula:     (""sair"" para encerrar) \n");
}

int prop(char *str1)
{
        if(!strcmp(str1,"1")||!strcmp(str1,"0")||!strcmp(str1,"P")||!strcmp(str1,"Q")||!strcmp(str1,"R")||!strcmp(str1,"S")||!strcmp(str1,"X")||!strcmp(str1,"U")||!strcmp(str1,"~P")||!strcmp(str1,"~Q")||!strcmp(str1,"~R")||!strcmp(str1,"~S")||!strcmp(str1,"~X")||!strcmp(str1,"~~P")||!strcmp(str1,"~~Q")||!strcmp(str1,"~~R")||!strcmp(str1,"~~S")||!strcmp(str1,"~~X"))
            {
                return 1; //se for do tipo P,Q,R,S,X,U,0,1,~P,~Q,~R,~S,~X,~U;
            }
return 0;


}
int valido(char c)
{
     if(c=='1'||c=='0'||c=='S'||c=='R'||c=='U'||c=='X'||c=='Q'||c=='P'||c=='('||c=='v'||c=='&'||c=='>'||c=='='||c=='~') // o (  é para informar que foi aberto e nao parar o programa se tiver ex: ~(PvQ)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int propc(char c)
{
    if(c=='1'||c=='0'||c=='S'||c=='R'||c=='U'||c=='X'||c=='Q'||c=='P'||c=='(') // o (  é para informar que foi aberto e nao parar o programa se tiver ex: ~(PvQ)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int input()
{
    /*retornar 1 se for bem formada, 0 para finalizar o programa e 2 para nao bem formada*/
    char str1[200],*p,str2[200];
    int i=0,aux=strlen(str1),pa=0,pf=0;
     

      gets(str1); 

    
    
        if(strcmp(str1,"sair"))
        {
         if(prop(&str1))
            {
                
                
                return 1;
                
            }
            
            
        else
            {

              for(i=0;i<aux;i++)
               {
                   if(valido(str1[i]))
                   {
                            if (str1[i]=='(')
                            {
                                 pa++;
                            }
                            else
                            {
                                if (str1[i]==')')
                                {
                                    pf++;
                                }
                            }        
                   
                   
                   
                        if (str1[i]=='~')
                        {
                                if (!propc(str1[i+1]))
                                {
                                     return 2;
                                }
                       
                         }
                        else
                        {
                             if ((propc(str1[i])&&propc(str1[i+1]))||(propc(str1[i])&&str1[i+1]=='~'))//trata PQ e P~Q
                                {
                                         return 2;
                                }
                            else
                                {
                                    if(str1[i]=='v'||str1[i]=='&'||str1[i]=='>'||str1[i]=='=')
                                        {
                                            if(!propc(str1[i-1])&&!propc(str1[i+1]))
                                             {
                                                return 2;
                                             }
                                        }
                                }
                       
                         
                        }
                  
                   }
                   else
                   {
                       return 2; //cacter invalido
                   }
                
                   
               } 


            if(pa!=pf)
            {
                return 2;
            }  
            
               
                 
                   
               return 1;        
            }


                
        }
        return 0; //para sair
}

void output (int i)
{
    if(i==0)
    {
        printf("\n O programa foi Finalizado \n");
        
    }
    else
    {
        if(i==1)
        {
            printf("\n E uma formula bem formada \n");
        }
        else
        {
            printf("\n Nao e uma formula bem formada \n");
        }
    }
    system("pause");
    system("cls");
}
int main()
{
   int aux=1;
    

     do
     {
        afabeto();
        output( aux=input ());
        
     } while (aux);
        
            
       
        
      
 
	
}

