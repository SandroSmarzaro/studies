const http = require('http');
const path = require('path');
const fs = require('fs');
const PORT = '8080';

http.createServer((req, res) => {
	const file = req.url === '/' ? 'index.html' : req.url;
	if (req.url === '/'){
		fs.readFile(
			path.join(__dirname, 'index.html'),
			(err, content) => {
				if (err) throw err;
				res.end(content);
			}
		)
	}
}).listen(PORT, () => {
	console.log(`Server working in https://localhost:${PORT}`);
});