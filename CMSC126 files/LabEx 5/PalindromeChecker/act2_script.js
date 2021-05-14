// external javascript file for Activity 2
// array functions used include split(), reverse(), and join()

// function to check if the word or phrase entered by user is a palindrome
 function checkString(){
    var userInput = document.getElementById("str").value;  // gets input from the user
    var userString = String(userInput); // converts the user input into a string
    
    
    if(userString.length == 0){ // checks if the requied field is empty
        alert("Please enter your string on the required field!"); // if so, the user will be alerted
    }else{

    let specialChar = /[^A-Za-z0-9]/g; // this is a regular expression, which checks if the string has non-alphanumberic characters
    let ogString = userString.toLowerCase().replace(specialChar, ''); // changes any uppercase letters into lowercase and removoes non-alphanumeric characters
    let reverseString = ogString.split('').reverse().join(''); // splits the letter of the string into array elements, reverses them and joins them back 

    if(ogString === reverseString){
        document.getElementById("output").innerHTML = "Hooray! Your string is a palindrome.";
    }else{
        document.getElementById("output").innerHTML = "Aw man! Your string is not a palindrome.";
        }
    }
}

document.getElementById("btn").addEventListener("click", checkString); // calls the function whenever the button is pressed