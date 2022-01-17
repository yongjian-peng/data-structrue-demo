package com.epay.common.util;

import org.apache.commons.codec.binary.Base64;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.security.SecureRandom;

/**
 * AES加解密工具类
 * @author epay
 * @date 2020/08/19
 */
public class AESUtils {

    private static final String DEFAULT_CIPHER_ALGORITHM = "AES/ECB/PKCS5Padding";//默认的加密算法

    /**
     * AES 加密操作(自定义key)
     *
     * @param content 待加密内容
     * @return 返回Base64转码后的加密数据
     */
    public static String encrypt(String content,String key) {
        try {
            if(null == content || "".equals(content)){
                return content;
            }
            Cipher cipher = Cipher.getInstance(DEFAULT_CIPHER_ALGORITHM);// 创建密码器

            byte[] byteContent = content.getBytes(StandardCharsets.UTF_8);

            cipher.init(Cipher.ENCRYPT_MODE, getKey(key));// 初始化为加密模式的密码器

            byte[] result = cipher.doFinal(byteContent);// 加密

            return Base64.encodeBase64String(result);//通过Base64转码返回
        } catch (Exception ex) {
//            logger.error("加密失败，直接返回原始值content=" + content);
//            Logger.getLogger(AESUtils.class.getName()).log(Level.SEVERE, null, ex);
        }
        return content;
    }

    /**
     * AES 解密操作(自定义key)
     *
     * @param content 待解密
     * @return str
     */
    public static String decrypt(String content,String key) {

        try {
            //实例化
            Cipher cipher = Cipher.getInstance(DEFAULT_CIPHER_ALGORITHM);

            //使用密钥初始化，设置为解密模式
            cipher.init(Cipher.DECRYPT_MODE, getKey(key));

            //执行操作
            byte[] result = cipher.doFinal(Base64.decodeBase64(content));

            return new String(result, StandardCharsets.UTF_8);
        } catch (Exception ex) {
//            logger.error("解密失败，直接返回原始值content=" + content);
//            Logger.getLogger(AESUtil.class.getName()).log(Level.SEVERE, null, ex);
        }
        return content;
    }

    /**
     * 生成加密秘钥
     *
     * @return key
     */
    public static SecretKey getKey(String strKey) {
        try {
            KeyGenerator _generator = KeyGenerator.getInstance( "AES" );
            SecureRandom secureRandom = SecureRandom.getInstance("SHA1PRNG" );
            secureRandom.setSeed(strKey.getBytes());
            _generator.init(128,secureRandom);
            return _generator.generateKey();
        }  catch (Exception e) {
            throw new RuntimeException( "初始化密钥出现异常" );
        }
    }

    public static void main(String[] args) {
        BufferedReader reader;
        String str = "1111E";
        String key = "111";
        System.out.println("AES加解密操作---E：加密   D：解密   Q：退出");
        do {
            reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("请输入操作代码：");
            try {
                str = reader.readLine();
                if("E".equalsIgnoreCase(str)){
                    System.out.print("请输入待加密字符串：");
                    str = reader.readLine();
                    System.out.println("加密后字符串："+ AESUtils.encrypt(str,key));
                }
                if("D".equalsIgnoreCase(str)){
                    System.out.print("请输入待解密字符串：");
                    str = reader.readLine();
                    System.out.println("解密后字符串："+ AESUtils.decrypt(str,key));
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }while (!"Q".equalsIgnoreCase(str));
    }

}