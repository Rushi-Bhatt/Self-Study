var $ = require('jquery');   //same way we load the jquery in server - we are loading it for client
var printTerms = require('./lib/printTerms');  //we are loading the module -same way we load for server

$(document).ready(function () {

    $.getJSON('/dictionary-api', printTerms);
    $('form').submit(e => {
        e.preventDefault();
        $.post('/dictionary-api', {term: $('#term').val(), defined: $('#defined').val()}, printTerms);
        document.forms[0].reset();
    });

});
