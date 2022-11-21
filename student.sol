pragma solidity 0.4.25;
pragma experimental ABIEncoderV2;

contract StudentRegister{
    struct student{
        uint studentId;
        string name;
        string course;
        uint totalMarks; 
    }

    student[] studentRecord;

    function register(uint studentId, string memory name, string memory course, uint totalMarks) public{
        studentRecord.push(student(studentId, name, course, totalMarks));
        students[studentId]=student(studentId, name, course, totalMarks);
    }

    mapping (uint=>student) students;
    function getStudentDetails(uint studentId) public view returns(uint, string memory, string memory, uint){
        return (students[studentId].studentId, students[studentId].name, students[studentId].course, students[studentId].totalMarks); 
    }

    function printAll() public view returns(student[] memory){
        return studentRecord;
    }

    function () public payable{
        revert("Enter proper Function");
    }

    recieve () public payable{
        revert("lol");
    }
}
