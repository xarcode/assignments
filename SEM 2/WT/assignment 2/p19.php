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
        #fname{
            font-size: 20px;
            border-radius:20px;
        }
        
    </style>
    <title>Reverse String</title>
</head>

<body>
    <form action="" method="POST">
        <label for="text">Enter the Username:</label>
        <input type="text" name="fname" id="fname"><br><br>
        <input type="submit" id="btn" value="Submit">
    </form>

    <?php

    $user = $_POST['fname'];
    echo "Entered username is: " . $user. "</br>";
    ?>
</body>

</html>