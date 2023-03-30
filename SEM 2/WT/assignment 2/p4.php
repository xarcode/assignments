<h3>
<?php
$temperatures = array(78, 60, 62, 68, 71, 68, 73, 85, 66, 64, 76, 63, 75, 76, 73, 68, 62, 73, 72, 65, 74, 62, 62, 65, 64, 68, 73, 75, 79, 73);


$sum = array_sum($temperatures);
$average = $sum / count($temperatures);
echo "Average temperature: " . round($average, 2) . " degrees<br>";

sort($temperatures);

echo "Seven lowest temperatures: ";
for ($i = 0; $i < 7; $i++) {
    echo $temperatures[$i] . " ";
}
echo "<br>";

echo "Seven highest temperatures: ";
for ($i = count($temperatures) - 1; $i >= count($temperatures) - 7; $i--) {
    echo $temperatures[$i] . " ";
}
echo "<br>";
?>
</h3>