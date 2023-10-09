var username = localStorage.getItem('username');


if (username) {
    document.getElementById('greeting').innerHtml = 'Привет, ' + username + '!';
}

document.getElementById('login').addEventListener('click', function() {
    
    var username = prompt('Ваше имя:');

    
    localStorage.setItem('username', username);

    
    document.getElementById('greeting').innerHtml = 'Привет, ' + username + '!';
});


document.getElementById('login_form').addEventListener('submit', function(e) {
    e.preventDefault();

    let username = document.getElementById('username').value;
    let password = document.getElementById('password').value;

    localStorage.setItem('username', username);
    localStorage.setItem('password', password);
      
    let greeting = document.getElementById('greeting');
    greeting.innerText = `Привет, ${username}!`;
});


window.onload = function() {
    let username = localStorage.getItem('username');
    let password = localStorage.getItem('password');
      
    if(username && password) {
        document.getElementById('username').value = username;
        document.getElementById('password').value = password;
  
        let greeting = document.getElementById('greeting');
        greeting.innerText = `Привет, ${username}!`;
    }
};