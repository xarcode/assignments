import java.io.*;
import jakarta.service.*;

public class one extends GenericServlet {
    public void service(ServletRequest req, ServletResponse res) throws IOException, ServletException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.print("<html>This is generic servlet</html>");
    }
}