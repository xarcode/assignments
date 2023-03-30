<?php
$ch = $_POST['value'];
if (!is_numeric($ch)) {
    echo "INVALID CHOICE";
} else {
    
    switch ($ch) {
        case 1:
            echo "MONDAY";
            break;
        case 2:
            echo "TUESDAY";
            break;
        case 3:
            echo "WEDNESDAY";
            break;
        case 4:
            echo "THURSDAY";
            break;
        case 5:
            echo "FRIDAY";
            break;
        case 6:
            echo "SATURDAY";
            break;
        case 7:
            echo "SUNDAY";
            break;

        default:
            echo "INVALID CHOICE";
            break;
    }
}
?>