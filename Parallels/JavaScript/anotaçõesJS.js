document.write('Write')             //apenas escreve
window.alert('Alert')               //caixa de apenas texto
window.confirm('Confirm')           //retorna true pra OK false pra cancelar
window.prompt('Prompt')             //possui entrada do usuári oque é retornado o valor inserido

var number                                              //global
let word;                                               //local
let object = {                                          //objeto
    name: 'test',
    age: 18,
    weith: 75.5,
    adm: false
}

const test = function (first, second){ return first + second;}      //Função Anônima

const test = (first, second) => {return first + second;}            //Arrow Function

function Person (name, age, weigth, adm) {                          //PascalCase x camelCase
    this.name = name;
    this.age = age;
    this.weigth = weigth;
    this.adm = adm;
}
const person = new Person("test", 18, 75.5, false);                 //objeto feito por constrututora


Number.parseInt(window.prompt('Prompt Int'))            //casting int
Number.parseFloat(window.prompt('Prompt Flaot'))        //casting float
Number(window.prompt('Prompt Int or Flaot'))            //atribuindo variavél
String(window.prompt('Prompt String'))                  //atribuindo variavél
number.toString();                                      //casting number to string
number.toFixed(2)                                       //quantas casas decimais deseja

number.toLocaleString('pt-BR', {style: 'currency', currency: 'BRL'})    //conversão em moeda BR
window.prompt(number + 'Test ')                                         //concatenação 
window.prompt(`${number} Test`)                                         //print de variváel no meio de string
word.legth                                                              //len da string
word.toUpperCase()                                                      //caixa alta
word.toLowerCase()                                                      //caixa baixa
word.replace('.', '-')                                                  //trocas
word.split(" ")                                                         //cria array de  strings cortando pelo caractere passado
word.join(" ")                                                          //junta strings com um caracter de conjunção passado 
word.includes("test")                                                   //retorna boleano se tem a string na variavél     

var array = new Array(number)                           //criação de array de number itens
array2 = [number, word];          
var array = array.concat(array2);                       //concatenação de array
array.indexOf(number);                                  //proucura o item na array e retorna seu index
word = array.join();                                    //transforma a array numa string
array.length                                            //quantidade de itens
array.push(number);                                     //empilha item
array.pop(number);                                      //desempilha item
array.reverse();                                        //inverte a array
array.shift();                                          //desenfilera   
array.sort();                                           //ordena de forma crescente
array.unshift(number);                                  //inseri item no [0]
array.splice(number, number);                           //a partir de number[index] remove numbers itens
array[0] = array2;                                      //criação de matrizes
Array.from(word)                                        //transformando um string em array

if (word == ""){
    throw new Error("Error occurred");                  //Lançamento de erro parando o software
}
try{                                                    //tenta executar o codigo, se recebe throw continua
    word++;
} catch (erro) {                                        //se ouver erro.menssage faz este bloco
    number++;
} finally {                                             //independente executa isso (opcional)
    number--;
}

for (let count = 0; count < 11; count++){
    if (count === 5){                                   //comparação de valor e tipo
        continue;                                       //a partir desse comando, todos comandos abaixo desse turno não são executados
    }
}
for (let char of word){                                 //o contador vira cada caractere de word(funciona para cada index de array)
    console.log(char);
}
for (let property in Person){                           //o contador vira o nome de cada atributo do objeto
    console.log(property[property]);
}

var element = document.getElementsByTagName('p')[0]     //atribuir a element o htlm reclacionados a p index 0
document.write(element.innerText)                               
window.write(element.innerHTML)                         //alteração  ou obtenção do codigo html no elemento obtido
var background = window.document.body
background.style.color = 'black'
element = document.getElementById('idd')                //atribuir a element todos os html reclacionados a idd
element = document.getElementsByName('name')            //atribuir a element todos os html reclacionados a name
element = document.getElementsByClassName('classe')     //atribuir a element todos os html reclacionados a classe
element = document.querySelector('div#idd')             //atribui a element todos elementos de div#idd
element = document.querySelectorAll('div.classe')       //atribui a element todos elementos de div.classe

var formulario = document.form[0]                      //atribuiu o 1º formulário a variavel
formulario = document.form["nome_formulário"]          //atribuindo por formulario especifico
formulario = document.form.item(0)                     //atribuindo o 1º formulario
formulario = document.form[0].id                       //atribuindo id do form

function sum(numberOne) {                              // Curryng Function
    return function (numberTwo) {
        return numberOne + numberTwo;
    }
}
const sum2 = sum(2);
sum2(3);