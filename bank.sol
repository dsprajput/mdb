pragma solidity 0.4.25;

contract Bank {
    int bal;
    constructor() public{
        bal=1;
    }

    function InputAndOutputParameters(int inputParam1) {
       bal =  inputParam1;
    }


    function getBalance() view public returns(int)
    {
        return bal;
    }
    function withdraw(int amt) public
    {
        if(bal<amt){
            revert("amount is not enough for withdrawl");
        }
        bal = bal -amt;
    }
    function deposit(int amt) public
    {
        bal = bal + amt;
    }

}
