// http://expressjs.com/
var app = require('express');
var server = app.createServer();

// http://senchalabs.github.com/connect/middleware-logger.html
server.use(app.logger());

// Serve the brunch example project as static content
server.use('/brunch', app.static(__dirname + '/../simplebrunch/brunch'));

// Main page
server.use('/', app.static(__dirname));


// https://github.com/cloudhead/cradle
var cradle = require('cradle');
var couchConn = new (cradle.Connection)({cache: false, raw: false});

// Hook to database, create if missing
var couchDB = couchConn.database('testdb');
couchDB.exists(function(err, exists) {
    if (err) {
        console.log('error', err);
    } else if (exists) {
        console.log('database found');
    } else {
        console.log('database missing');
        couchDB.create();
    }
});

// CouchDB access. TODO's:
// - Replace /couch with database name
// - Check https://github.com/mikeal/node.couchapp.js/tree/ -> Create DB views etc etc.
server.get('/couch/:docid', function(req, res) {
	couchDB.get(req.params.docid, function(err, doc) {
	    if (err) {
	    	res.send('Missing', 404);
	    } else {
	    	res.contentType('application/json');
			res.send(doc);
	    }
	});
});

// Start server
server.listen(23432, function() {
	console.log('listening...');
});
