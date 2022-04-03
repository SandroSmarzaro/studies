//const exportModules = require("./testModules");

//node testIndex --greating "How are you?" --name "San"
//console.log(`Hi ${exportModules("--name")}. ${"--greting"}?`);

//npm init -y
//npm outdated
/*
process.stdout.write()
process.stdin.on("data", data => {
    process.stdout.write (data.toSring().trim() + '\n')
    process.exit()
})
process.on("exit");
*/

/*
let timeOut = 1000;
const finished = () => console.log('done');
let timer = setTimeout(finished,timeOut);

clearTimeout(timer)         //cancela a execução da função

const checking = () => console.log('check');
let interval = setInterval(checking, timeOut);

clearInterval(interval)
*/

/*
const { EventEmitter } = require('events') 
const event = new EventEmitter()

event.emit('Emetindo', "parametro")
event.on('Emetindo', (parametro) => console.log("Ouvindo eventos"))
event.once('Emetindo', (parametro) => console.log("Ouvindo eventos"))

const {inherits} = require('util')
function Character(name){
    this.name = name
}
inherits(Character, EventEmitter)
const fulano = new Character('Fulano')
fulano.on('help', () => console.log("Ei fulano"))
fulano.emit('help')
*/

/*
const express = require("express");
const userRoute = require('./usersRoute');
const app = express();
const port = 3000;
userRoute(app)
app.get("/", (requisicao, resposta) => {resposta.send("Test")})
app.listen(port, () => {console.log("Rodando");});
*/