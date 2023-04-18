<?php
    $str = "National Institute of Technology Warangal";
    echo "Length is:". strlen($str)."</br>";
    echo "Reverse is:". strrev($str)."</br>";
    echo "position of T is:". strpos($str,'T')."</br>";
    echo "Word Count is:". str_word_count($str)."</br>";
    echo "Is string same or not:". strcmp($str,"National")."</br>";
    echo "Replace:" .str_replace("Warangal","Trichy",$str);
?>