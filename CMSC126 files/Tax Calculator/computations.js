
// external javascript for income tax computation

var monthlyIncome = document.getElementById("incomePerMonth").value; // gets user input from form field

// function to calculate either GSIS or SSS deductions per month and annum
function insuranceDeduc(monthlyIncome){
    var gsis = document.getElementById('yes'); // gets user input from form in html
    var sss = document.getElementById('no');
    var monthlyInsurance;
    var total;

    if(gsis.checked==true){ // checks if this particular option has been selected by the user
        monthlyInsurance = monthlyIncome*0.09;
        total = monthlyInsurance*12;
    }
    else if(sss.checked==true){
        monthlyInsurance = monthlyIncome*0.11;
        total = monthlyInsurance*12;
    }
    return total; //returns value for insurance
}

// function to calculate the deductions based on the number of dependents the user has
function dependentsDeduc(){
   
    var dep0 = document.getElementById('0'); // gets user input from form in html
    var dep1 = document.getElementById('1');
    var dep2 = document.getElementById('2');
    var dep3 = document.getElementById('3');
    var dep4 = document.getElementById('4');
    var total;

    if(dep0.checked==true){ // checks what choice has been selected by user
        total = 0;
    }
    else if(dep1.checked==true){
        total = 50000;
    }
    else if(dep2.checked==true){
        total = 2*50000;
    }
    else if(dep3.checked==true){
        total = 3*50000;
    }
    else if(dep4.checked==true){
        total = 4*50000;
    }
    
    return total; // returns value for dependents
}

// function to calculate the for PagIbig, Philhealth and overall total deductions
function totalDeduc(monthlyIncome, insurance, dependents){
    
    var pagibig = (monthlyIncome*0.01375)*12; // calculates pagibig deduction
    var philhealth = (monthlyIncome* 0.035)*12; // calculates philhealth deduction
    
    var total = insurance + dependents + pagibig + philhealth + 50000; // calculates total deduction

return total; //returns value for deductions
}

// function to calculate the gross income, taxable income, and payable tax based on the bracketing system
function totalTax(monthlyIncome, deductions){

    var grossIncome = monthlyIncome*13; // calculates for yearly income + 13th month pay
    var taxableIncome = grossIncome - deductions; // calculates for the part of the income that can be taxed
    var payableTax;

    if(taxableIncome >= 0 && taxableIncome <=250000){ // this part is based on the given table (bracket system)
        payableTax = 0;
    } 
    else if(taxableIncome >= 250000 && taxableIncome <= 400000){
        payableTax = (taxableIncome-250000)*0.20;
    }
    else if(taxableIncome >= 400000 && taxableIncome <= 800000){
        payableTax = ((taxableIncome-400000)*0.250)+30000;
    }
    else if(taxableIncome >= 800000 && taxableIncome <= 2000000){
        payableTax = ((taxableIncome-800000)*0.30)+130000;
    }
    else if(taxableIncome >= 2000000 && taxableIncome <= 8000000){
        payableTax = ((taxableIncome-2000000)*0.32)+490000;
    }
    else if(taxableIncome > 8000000){
        payableTax = ((taxableIncome-8000000)*0.35)+2410000;
    }

    return payableTax.toFixed(2); // returns value for payables
}

function thousands_separators(payables){ // function to add commas to the payable tax value
    var payables_parts = payables.toString().split(".");
    payables_parts[0] = payables_parts[0].replace(/\B(?=(\d{3})+(?!\d))/g, ",");
    return payables_parts.join(".");
  }

// this function in linked to the submit button and calls all the other functions to display the final figure of the payable tax
function display() {
   
    var monthlyIncome = document.getElementById("incomePerMonth").value;
    var insurance = insuranceDeduc(monthlyIncome);
    var dependents = dependentsDeduc();
    var deductions = totalDeduc(monthlyIncome, insurance, dependents);
    var payables = totalTax(monthlyIncome, deductions);
    var finaltotal = thousands_separators(payables);
    
    document.getElementById("demo").innerHTML = "₱ " + finaltotal; // displays the final output to the site
  }
