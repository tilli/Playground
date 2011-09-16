// Import and create web server
var app = require('express');
var server = app.createServer();

// Serve the brunch example project as static content
server.use('/brunch', app.static(__dirname + '/../simplebrunch/brunch'));

// Main page
server.use('/', app.static(__dirname));

//server.get('/', function(req, res) {
//});

// Start server
server.listen(23432, function() {
	console.log('listening x...');
});
