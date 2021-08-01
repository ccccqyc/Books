/**
 * 原理:
 * a^a = 0
 * a^0 = a
 *
 *
 */
public class JZ40_FindNumsAppearO {
    public int[] FindNumsAppearOnce(int[] array) {
        // write code here
        int tempi = array[0];
        for (int i = 1; i < array.length; i++) {
            tempi ^= array[i];
        }
        int tempj = 1;
        //找到 数组中俩数第一次出现的不同
        while ((tempi & tempj) == 0) {
            tempj <<= 1;
        }

        int i = 0, j = 0;
        for (int value : array) {
            if ((value & tempj) != 0) {
                i ^= value;
            } else {
                j ^= value;
            }
        }

        int[] temp = {i, j};
        if (i > j) {
            temp[0] = j;
            temp[1] = i;
        }

        return temp;
    }

}
