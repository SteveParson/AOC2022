import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Day5 {

    public static void main(String[] args) throws IOException {
        List<String> lines = Files.readAllLines(new File(args[0]).toPath());
        getSolution(lines, getStacks(lines), 1);
        getSolution(lines, getStacks(lines), 2);
    }

    private static void getSolution(List<String> lines, List<Stack<String>> stacks, int part) {
        for (String line : lines) {
            if (!line.startsWith("move")) {
                continue;
            }

            String[] lineElements = line.strip().split(" ");
            int numberOfItemsToPop = Integer.parseInt(lineElements[1]);
            Stack<String> srcStack = stacks.get(Integer.parseInt(lineElements[3]) - 1);
            Stack<String> destStack = stacks.get(Integer.parseInt(lineElements[5]) - 1);

            if (part == 1) {
                for (int i = 0; i < numberOfItemsToPop; i++) {
                    destStack.push(srcStack.pop());
                }
            }

            if (part == 2) {
                moveStackItemsPart2Style(numberOfItemsToPop, srcStack, destStack);
            }
        }
        System.out.printf("Solution for part %d: %s\n", part, getTopOfStack(stacks));
    }

    private static void moveStackItemsPart2Style(int numberOfItemsToPop, Stack<String> srcStack, Stack<String> destStack) {
        if (numberOfItemsToPop == 1) {
            destStack.push(srcStack.pop());
        } else {
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < numberOfItemsToPop; i++) {
                sb.append(srcStack.pop());
            }

            for (int i = numberOfItemsToPop - 1; i >= 0; i--) {
                destStack.push(String.valueOf(sb.charAt(i)));
            }
        }
    }

    private static String getTopOfStack(List<Stack<String>> stacks) {
        StringBuilder sb = new StringBuilder();
        for (Stack<String> stack : stacks) {
            sb.append(stack.toString().charAt(stack.toString().length() - 2));
        }
        return sb.toString();
    }

    private static List<Stack<String>> getStacks(List<String> lines) {
        int numberOfStacks = getNumberOfStacks(lines);
        List<Stack<String>> stacks = new ArrayList<>();

        for (int i = 0; i < numberOfStacks; i++) {
            stacks.add(extractStack(lines, i));
        }

        return stacks;
    }

    private static Stack<String> extractStack(List<String> lines, int stackNumber) {
        StringBuilder sb = new StringBuilder();
        for (String line : lines) {
            if (line.strip().startsWith("1")) {
                break;
            }

            char element = line.charAt(1 + 4 * stackNumber);
            if (element != ' ') {
                sb.append(element);
            }
        }

        return convertStringToStack(sb.toString());
    }

    private static Stack<String> convertStringToStack(String stack) {
        Stack<String> theStack = new Stack<>();
        for (int i = stack.length() - 1; i >= 0; i--) {
            theStack.push(String.valueOf(stack.charAt(i)));
        }
        return theStack;
    }

    private static int getNumberOfStacks(List<String> lines) {
        for (String line : lines) {
            if (line.strip().startsWith("1")) {
                String[] stackNumberLabels = line.strip().split(" ");
                return Integer.parseInt(stackNumberLabels[stackNumberLabels.length - 1]);
            }
        }
        return -1;
    }
}
