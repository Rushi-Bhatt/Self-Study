//handling chat using native javascript


var socket = io();  //JAvascript 
var chatUsername = document.querySelector('#chat-username');
var chatMessage = document.querySelector('#chat-message');

socket.on('connect', function() { //detect the connection on client side
  var chatForm = document.forms.chatForm;  //document.forms - list of alll the forms in the document

  if (chatForm) {
    chatForm.addEventListener('submit', function(e) {
      e.preventDefault();
      socket.emit('postMessage',{   //emit the postmessage event, which will be received by the server and handled there
        username: chatUsername.value,
        message: chatMessage.value,
      });
      chatMessage.value='';
      chatMessage.focus();
    }); //chatform event

    socket.on('updateMessages', function(data) { //handle the updateMessages event emitted by the server
      showMessage(data);
    }); //updateMessages
  } //chatform
}); //socket

function showMessage(data) {
  var chatDisplay = document.querySelector('.chat-display');
  var newMessage = document.createElement('p');

  if (chatUsername.value == data.username) {
    newMessage.className = 'bg-success chat-text';
  } else {
    newMessage.className = 'bg-info text-warning chat-text';
  }

  newMessage.innerHTML = '<strong>' + data.username + '</strong>: ' + data.message;
  chatDisplay.insertBefore(newMessage, chatDisplay.firstChild);
}
