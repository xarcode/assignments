<html>

<head>
    <style>
        body{
            padding: 0;
            margin: 0;
            text-align: center;
            font-size: 30px;
        }
        form{
            width:300px;
            height:200px;
            margin: auto;
            margin-top: 30px;
            border: 1px solid black;
            text-align: center;
            border-radius: 10px;
            padding: 5px;
            background-color: blanchedalmond; 
        }
        #btn{
            background-color: green;
            border: none;
            border-radius: 3px;
            font-size: 20px
        }
        #text{
            font-size: 20px
        }
        
    </style>
    <title>Reverse String</title>
</head>

<body>
    <form action="" method="POST">
        <label for="text">Enter the String:</label>
        <input type="text" name="text" id="text"><br><br>
        <input type="submit" id="btn" value="Reverse">
    </form>

    <?php

    $str = $_POST['text'];
    $rev = strrev($str);
    echo "Reverse is: " . $rev. "</br>";
    if($str == $rev)
        echo "String is Palindrome";
    else
        echo "String is not Palindrome";


    ?>
</body>

</html>