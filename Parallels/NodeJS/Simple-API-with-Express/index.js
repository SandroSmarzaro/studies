const express = require('express');
const app = express(); 
const PORT = '8080';

app.use( express.json() );

app.get('/person',(req, res) => {
	res.status(200).send({
		name: 'Sandro',
		age: 20
	})
});

app.post('/creator/:id', (req, res) => {
	const { id } = req.params;
	const { data} = req.body;

	if (!data) {
		res.status(418).send({ message: 'Without data!' });
	}
	res.send({
		response: 'Okay'
	})
});

app.listen(
	PORT,
	() => console.log(`Working in http://localhost:${PORT}`)
);