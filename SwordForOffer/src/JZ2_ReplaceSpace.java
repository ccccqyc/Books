/**
 * 替换空格
 */
public class JZ2_ReplaceSpace {
    public String replaceSpace(String s) {
        // write code here
        char temp;
        StringBuilder ss = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            temp = s.charAt(i);
            if (temp == ' ') {
                ss.append("%20");
                continue;
            }
            ss.append(temp);
        }
        return ss.toString();
    }
}