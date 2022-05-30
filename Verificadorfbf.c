//Programa que  diz se a formula e bem formada ou nao 
// o programa deve ler  a formula e assegurar se ela  bem formada ou nao*/

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
return 0; //se nao for 0


}
int valido(char c) // analisa se é um caracter valido, ou seja se pertece ao dicionario de simbolos
{
     if(c=='1'||c=='0'||c=='S'||c=='R'||c=='U'||c=='X'||c=='Q'||c=='P'||c=='('||c=='v'||c=='&'||c=='>'||c=='='||c=='~') // o (  é para informar que foi aberto e nao parar o programa se tiver ex: ~(PvQ)
    {
        return 1; //retorna 1 se sim
    }
    else
    {
        return 0; //retorna 0 se nao
    }
}
int propc(char c) //função quer retorna 1 se o caracter faz é por se so um fbf
{
    if(c=='1'||c=='0'||c=='S'||c=='R'||c=='U'||c=='X'||c=='Q'||c=='P'||c=='(') // o (  é para informar que foi aberto e nao parar o programa se tiver ex: ~(PvQ)
    {
        return 1; //retorna 1 se sim
    }
    else
    {
        return 0; //retona 0 se nao
    }
}

int input() //fução principal de entrada e verificação
{
    /*retornar 1 se for bem formada, 0 para finalizar o programa e 2 para nao bem formada*/
    char str1[200];
    int i=0,aux=strlen(str1),pa=0,pf=0; // pa= parenteses abertos pf= parenteses fechados
     

      gets(str1); // entrada da formula

    
    
        if(strcmp(str1,"sair")) //verifica se o usuario quer sair do programa
        {
         if(prop(&str1)) //verifica se é uma fbf de 2 cacteres no maximo
            {
                
                
                return 1; // 1 se sim 
                
            }
            
            
        else
            {

              for(i=0;i<aux;i++) //for que irar pecorrer toda a string caracter por caracter
               {
                   if(valido(str1[i])) // verifica se é um carcter valido
                   {
                            if (str1[i]=='(') //verifica se abriu o parenteses
                            {
                                 pa++;
                            }
                            else
                            {
                                if (str1[i]==')') //verfica se fechou o parenteses
                                {
                                    pf++;
                                }
                            }        
                   
                   
                   
                        if (str1[i]=='~') //verifica se nao tem so o negado
                        {
                                if (!propc(str1[i+1]))
                                {
                                     return 2; //caso haja configurações do tipo ~v; ~&  retorna 2 que é fomula mal formada
                                }
                       
                         }
                        else
                        {
                             if ((propc(str1[i])&&propc(str1[i+1]))||(propc(str1[i])&&str1[i+1]=='~'))//trata PQ e P~Q
                                {
                                         return 2; //caso verdaddeiro
                                }
                            else
                                {
                                    if(str1[i]=='v'||str1[i]=='&'||str1[i]=='>'||str1[i]=='=') //verfica se o carcter posterior ao conectivos é um simbolo proposicional.
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
                       return 3; //cacter invalido
                   }
                
                   
               } 


            if(pa!=pf) // se quantidade de parenteses abertos for diferente dos fechados
            {
                return 2; //se diferente entao mau formado
            }  
            
               
                 
                   
               return 1;        //caso ele passou por todos esses testes e nao retornou 2, então é FBF
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
                if(i==2)
                {
                    printf("\n Nao e uma formula bem formada \n");
                }
                else
                {
                    
                    printf("\n Caracteres nao validos \n");
                    
                }  
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

