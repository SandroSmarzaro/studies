const os = require('os');

const { freemem, totalmem } = os;

function convertByte2MegaByte(number) {
	return (number / 1024) / 1024 ;
}

setInterval(() => {
	const totalMemory = convertByte2MegaByte(totalmem());
	const freeMemory = convertByte2MegaByte(freemem());
	const usagePercent = (freeMemory / totalMemory) * 100;

	const status = {
		total: `${totalMemory.toFixed(2)} MB`,
		free: `${freeMemory.toFixed(2)} MB`,
		usage: `${usagePercent.toFixed(2)} %`
	}
	console.clear();
	console.table(status);
}, 500);
