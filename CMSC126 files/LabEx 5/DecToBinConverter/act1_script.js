// external javascript file for Activity 1
// array functions used include push(), reverse(), and join()

// function to convert decimal user input into binary
    function convertNum() {

        var userNum = document.getElementById('num').value; // gets user input
        let binaryNum = new Array(); // creates a new array
        var remainder = 0;
        
        if(userNum == ""){ // checks if the required field is filled out
            alert("Please enter a number on the required field!"); // if not, the user will be alerter
        }

        else{

        while (userNum >= 2) { 
            remainder = userNum % 2;
            binaryNum.push(remainder); // remainderis added to the beginning of the array as long as userNum is greater than or equal to 2
            userNum = (userNum - remainder) / 2;
        }

        binaryNum.push(userNum);
        binaryNum = binaryNum.reverse().join(''); // reverses array and joins them
        document.getElementById("output").innerHTML = binaryNum; // displays the final number to the site
        
    }
}

    document.getElementById("btn").addEventListener("click", convertNum); // calls the function convertNum() whenever the 'Submit' button is clicked