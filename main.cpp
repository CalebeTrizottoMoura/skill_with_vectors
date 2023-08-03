#include <iostream>
#include <string>
#include <climits>
#include <iomanip>

double calculator_average_age(double average_age, int sum_age, int numb_people){
    average_age = (double) sum_age / numb_people;
    return average_age;
}

double calculator_average_height(double average_height, double sum_height, int numb_people){
    average_height = sum_height / numb_people;
    return average_height;
}

double calculator_percentage_femenine(double percentage_femenine, int sum_femenine, int numb_people){
    percentage_femenine = (double) sum_femenine / numb_people * 100;
    return percentage_femenine;
}

double calculator_percentage_masculine(double percentage_masculine, int sum_masculine, int numb_people){
    percentage_masculine = (double) sum_masculine / numb_people * 100;
    return percentage_masculine;
}

void procedure_sum_gender(char array_gender, int *sum_femenine, int *sum_masculine, bool *control_sum_gender){
    if(array_gender == 'F' || array_gender == 'f'){
        (*sum_femenine)++;
        *control_sum_gender = false;
    }else if(array_gender == 'M' || array_gender == 'm'){
        (*sum_masculine)++;
        *control_sum_gender = false;
    }else{
        std::cout << "Por favor, digite 'F' para feminino ou 'M' para masculino.\n";
    }
}

void people_data(int numb_people, int *code, int *sum_femenine, int *sum_masculine, int *sum_age, double *sum_height,
                 std::string *array_name, char *array_gender, int *array_age, double *array_height){      
    bool control_sum_gender = true; 
    for(int i = 0; i < numb_people; i++){
        std::cin.ignore(INT_MAX, '\n');
        code[i] = i + 1000;

        std::cout << "========= DADOS DA " << i + 1 << "� PESSOA =========\n";
        std::cout << "Nome: ";
        getline(std::cin, array_name[i]);

        do{
            std::cout << "Sexo (F/M): ";
            std::cin >> array_gender[i];

            procedure_sum_gender(array_gender[i], sum_femenine, sum_masculine, &control_sum_gender);
        }while(control_sum_gender);

        std::cout << "Idade: ";
        std::cin >> array_age[i];
        *sum_age += array_age[i];
        
        std::cout << "Altura: ";
        std::cin >> array_height[i];
        *sum_height += array_height[i];
        system("cls");
    }
}

void main_menu(int *option){
    std::cout << "========= MENU PRINCIPAL =========\n";
    std::cout << "1 - Listar dados\n";
    std::cout << "2 - M�dia das idade\n";
    std::cout << "3 - M�dia das alturas\n";
    std::cout << "4 - Porcentagem\n";
    std::cout << "5 - Alterar dados\n";
    std::cout << "6 - Sair\n\n";
    std::cout << "Digite o n�mero da op��o desejada: ";
    std::cin >> *option;
    system("cls");
}

void data_list(int numb_people, std::string array_name[], char array_gender[], int array_age[], double array_height[], 
               int code[]){
    std::cout << "========= LISTAGEM DE DADOS =========\n";
    for(int i = 0; i < numb_people; i++){
        std::cout << "------------- " << i + 1 << "� PESSOA -------------\n";
        std::cout << "Nome: " << array_name[i] << std::endl;
        std::cout << "Sexo: " << array_gender[i] << std::endl;
        std::cout << "Idade: " << array_age[i] << std::endl;
        std::cout << "Altura: " << array_height[i] << std::endl;                    
        std::cout << "-------------------------------------\n";
        std::cout << "C�digo: " << code[i] << std::endl;
        std::cout << "-------------------------------------\n\n";
    }
}

void age_average(double average_age){
    std::cout << "========= M�DIA IDADES =========\n";
    std::cout << "A m�dia geral das idades foi de " << average_age << " anos.\n\n";
}

void height_average(double average_height){
    std::cout << "========= M�DIA ALTURAS =========\n";
    std::cout << "A m�dia geral das alturas foi de " << average_height << " m.\n\n";
}

void percentage(double percentage_femenine, int sum_femenine, double percentage_masculine, int sum_masculine){
    std::cout << "========= PORCENTAGEM =========\n";
    std::cout << "Mulheres: " << percentage_femenine << "% (" << sum_femenine << " participantes)\n";
    std::cout << "Homens: " << percentage_masculine << "% (" << sum_masculine << " participantes)\n";
    std::cout << "Total: " << percentage_femenine + percentage_masculine << "% (" 
    << sum_femenine + sum_masculine << " participantes)\n\n";
}

void menu_change(int *internal_option, int *change_code){
    std::cout << "========= MENU DE ALTERA��ES =========\n";
    std::cout << "1 - Alterar o nome\n";
    std::cout << "2 - Alterar o sexo\n";
    std::cout << "3 - Alterar a idade\n";
    std::cout << "4 - Alterar a altura\n";
    std::cout << "5 - Sair\n\n";
    std::cout << "Digite o n�mero da op��o desejada: ";
    std::cin >> *internal_option;
    system("cls");

    if(*internal_option != 5){
        std::cout << "========= MENU DE ALTERA��ES =========\n";
        std::cout << "Agora, digite o 'c�digo da pessoa' para localizarmos os dados: ";
        std::cin >> *change_code;
        std::cin.ignore(INT_MAX, '\n');
        system("cls");
    }
}

void name_change(std::string *array_name, char array_gender, int array_age, double array_height, int *cont_new){
    std::cout << "========= ALTERAR NOME =========\n";
    std::cout << "Nome: " << *array_name << "  <-----\n";
    std::cout << "Sexo: " << array_gender << std::endl;
    std::cout << "Idade: " << array_age << std::endl;
    std::cout << "Altura: " << array_height << std::endl;

    std::string new_name;
    std::cout << "\nDigite o novo nome: ";
    getline(std::cin, new_name);

    *array_name = new_name;
    *cont_new = 1;
}

void gender_change(std::string array_name, char *array_gender, int array_age, double array_height, int *cont_new){
    std::cout << "========= ALTERAR SEXO =========\n";
    std::cout << "Nome: " << array_name << std::endl;
    std::cout << "Sexo: " << *array_gender << "  <-----\n";
    std::cout << "Idade: " << array_age << std::endl;
    std::cout << "Altura: " << array_height << std::endl;

    char new_gender;
    std::cout << "\nDigite o novo sexo: ";
    std::cin >> new_gender;
    *array_gender = new_gender;
    *cont_new = 1;
}

void age_change(std::string array_name, char array_gender, int *array_age, double array_height, int *cont_new){
    std::cout << "========= ALTERAR IDADE =========\n";
    std::cout << "Nome: " << array_name << std::endl;
    std::cout << "Sexo: " << array_gender << std::endl;
    std::cout << "Idade: " << *array_age << "  <-----\n";
    std::cout << "Altura: " << array_height << std::endl;

    int new_age = 0;
    std::cout << "\nDigite a nova idade: ";                                    
    std::cin >> new_age;
    
    *array_age = new_age;
    *cont_new = 1;
}

void height_change(std::string array_name, char array_gender, int array_age, double *array_height, int *cont_new){
    std::cout << "========= ALTERAR ALTURA =========\n";
    std::cout << "Nome: " << array_name << std::endl;
    std::cout << "Sexo: " << array_gender << std::endl;
    std::cout << "Idade: " << array_age << std::endl;
    std::cout << "Altura: " << *array_height << "  <-----\n";

    double new_height = 0;
    std::cout << "\nDigite a nova altura: ";                                  
    std::cin >> new_height;
    
    *array_height = new_height;
    *cont_new = 1;
}

int main(){
    setlocale(LC_ALL, "portuguese");
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "========= MENU INICIAL =========\n";
    std::cout << "Quantas pessoas far�o parte da an�lise? ";
    int numb_people;
    std::cin >> numb_people;

    int sum_age = 0, sum_masculine = 0, sum_femenine = 0, array_age[numb_people], code[numb_people];
    std::string array_name[numb_people];
    double array_height[numb_people], sum_height = 0, average_age = 0, average_height = 0, percentage_femenine = 0, 
           percentage_masculine = 0;
    char array_gender[numb_people];
    system("cls");
    
    people_data(numb_people, code, &sum_femenine, &sum_masculine, &sum_age, &sum_height, array_name, array_gender,
                array_age, array_height);

    average_age = calculator_average_age(average_age, sum_age, numb_people);
    average_height = calculator_average_height(average_height, sum_height, numb_people);

    percentage_femenine = calculator_percentage_femenine(percentage_femenine, sum_femenine, numb_people);
    percentage_masculine = calculator_percentage_masculine(percentage_masculine, sum_masculine, numb_people);

    std::cin.ignore(INT_MAX, '\n');

    int option = 0, change_code = 0, internal_option = 0, cont = 0, cont_new = 0;

    do{
        if(cont > 0 && internal_option != 5){
            system("pause");
        }else{
            internal_option = 0;
        }
        system("cls");
        cont++;

        main_menu(&option);

        switch(option){
            case 1:
                data_list(numb_people, array_name, array_gender, array_age, array_height, code);
                break;
            case 2:
                age_average(average_age);
                break;
            case 3:
                height_average(average_height);
                break;
            case 4:
                percentage(percentage_femenine, sum_femenine, percentage_masculine, sum_masculine);
                break;
            case 5:
                do{
                    if(cont_new > 0){
                        cont_new = 0;
                        system("cls");
                        std::cout << "========= RESULTADO =========\n";
                        std::cout << "Dados alterados com sucesso!\n\n";
                        system("pause");
                        system("cls");
                    }

                    menu_change(&internal_option, &change_code);
                    
                    switch(internal_option){
                        case 1:                     
                            for(int i = 0; i < numb_people; i++){
                                if(code[i] == change_code){
                                    name_change(&array_name[i], array_gender[i], array_age[i], array_height[i], &cont_new);
                                    break; 
                                }
                            }
                            break;
                        case 2: 
                            for(int i = 0; i < numb_people; i++){
                                if(code[i] == change_code){
                                    gender_change(array_name[i], &array_gender[i], array_age[i], array_height[i], &cont_new);
                                    //corre��o
                                    sum_femenine = 0;
                                    sum_masculine = 0;
                                    bool control_sum_gender = true;

                                    procedure_sum_gender(array_gender[i], &sum_femenine, &sum_masculine, &control_sum_gender);

                                    percentage_femenine = calculator_percentage_femenine(percentage_femenine, sum_femenine, numb_people);
                                    percentage_masculine = calculator_percentage_masculine(percentage_masculine, sum_masculine, numb_people);
                                    break; 
                                }
                            }
                            break;
                        case 3: 
                            for(int i = 0; i < numb_people; i++){
                                if(code[i] == change_code){
                                    age_change(array_name[i], array_gender[i], &array_age[i], array_height[i], &cont_new);

                                    int sum_new_age = 0;
                                    for(int i = 0; i < numb_people; i++){
                                        sum_new_age += array_age[i];
                                    }

                                    average_age = calculator_average_age(average_age, sum_new_age, numb_people);                      
                                    break; 
                                }
                            }
                            break;
                        case 4: 
                            for(int i = 0; i < numb_people; i++){
                                if(code[i] == change_code){
                                    height_change(array_name[i], array_gender[i], array_age[i], &array_height[i], &cont_new);

                                    double sum_new_height = 0;
                                    for(int i = 0; i < numb_people; i++){
                                        sum_new_height += array_height[i];
                                    }

                                    average_height = calculator_average_height(average_height, sum_new_height, numb_people); 
                                    break; 
                                }
                            }
                            break;
                        case 5:
                            break;
                        default:
                            std::cout << "========= OP��O INV�LIDA =========\n";
                            std::cout << "Por favor, digite um n�mero de 1 at� 5.\n\n";
                            break;
                    }
                }while(internal_option != 5);

                break;
            case 6:
                std::cout << "========= SAINDO =========\n";
                break;
            default:
                std::cout << "========= OP��O INV�LIDA =========\n";
                std::cout << "Por favor, digite um n�mero de 1 at� 6.\n\n";
                break;
        }
    }while(option != 6);
      
    return 0;
}