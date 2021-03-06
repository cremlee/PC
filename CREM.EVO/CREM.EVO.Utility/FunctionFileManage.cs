﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Collections;
namespace CREM.EVO.Utility
{
   public class FunctionFileManage
    {
       private static string FILE_BASE  = "EVO.base.xml";
       private static string FILE_CLEAN = "EVO.clean.xml";
       private static string FILE_COM = "EVO.com.xml";
       private static string FILE_CONF = "EVO.conf.xml";
       private static string FILE_ID = "EVO.ID.xml";
       private static string FILE_ING = "EVO.Ingredient.xml";
       private static string FILE_DRINKMAP = "EVO.DrinkMap.xml";
       private static string FILE_COLOR = "EVO.LedSetting.xml";

        private static string _dbfilePath;
       private static string _outportfilePath="./config/";
       public static void SetDBFilePath(string a) { _dbfilePath = a; }
        public static bool ExportDB(string filePath)
        {
            ArrayList filebuf = new ArrayList();
            //byte[] readbuf;
            //int filelen;
            if (!Directory.Exists(_outportfilePath))
            {
                Directory.CreateDirectory(_outportfilePath);
            }
            try
            {

                
               // FilebufMake(ref filebuf, FileType.FILE_BASE);
                foreach (var item in Enum.GetValues(typeof(FileType)))
                {
                    FilebufMake(ref filebuf, (FileType)item);
                }
              /*  fs = new FileStream(_outportfilePath + FILE_CLEAN, FileMode.Open);
                readbuf = new byte[fs.Length];
                filelen = fs.Read(readbuf, 0, (int)fs.Length);
                fs.Close();

                filebuf.Add((byte)0x02);
                filebuf.Add((byte)(filelen >> 8));
                filebuf.Add((byte)(filelen));
                for (int i = 0; i < readbuf.Length; i++)
                {
                    filebuf.Add(readbuf[i]);
                }
                fs = new FileStream(_outportfilePath + FILE_COM, FileMode.Open);
                readbuf = new byte[fs.Length];
                filelen = fs.Read(readbuf, 0, (int)fs.Length);
                fs.Close();

                filebuf.Add((byte)0x03);
                filebuf.Add((byte)(filelen >> 8));
                filebuf.Add((byte)(filelen));
                for (int i = 0; i < readbuf.Length; i++)
                {
                    filebuf.Add(readbuf[i]);
                }
                fs = new FileStream(_outportfilePath + FILE_CONF, FileMode.Open);
                readbuf = new byte[fs.Length];
                filelen = fs.Read(readbuf, 0, (int)fs.Length);
                fs.Close();

                filebuf.Add((byte)0x04);
                filebuf.Add((byte)(filelen >> 8));
                filebuf.Add((byte)(filelen));
                for (int i = 0; i < readbuf.Length; i++)
                {
                    filebuf.Add(readbuf[i]);
                }
                fs = new FileStream(_outportfilePath + FILE_ID, FileMode.Open);
                readbuf = new byte[fs.Length];
                filelen = fs.Read(readbuf, 0, (int)fs.Length);
                fs.Close();

                filebuf.Add((byte)0x05);
                filebuf.Add((byte)(filelen >> 8));
                filebuf.Add((byte)(filelen));
                for (int i = 0; i < readbuf.Length; i++)
                {
                    filebuf.Add(readbuf[i]);
                }
                fs = new FileStream(_outportfilePath + FILE_ING, FileMode.Open);
                readbuf = new byte[fs.Length];
                filelen = fs.Read(readbuf, 0, (int)fs.Length);
                fs.Close();

                filebuf.Add((byte)0x06);
                filebuf.Add((byte)(filelen >> 8));
                filebuf.Add((byte)(filelen));
                for (int i = 0; i < readbuf.Length; i++)
                {
                    filebuf.Add(readbuf[i]);
                }

                fs = new FileStream(_outportfilePath + FILE_DRINKMAP, FileMode.Open);
                readbuf = new byte[fs.Length];
                filelen = fs.Read(readbuf, 0, (int)fs.Length);
                fs.Close();

                filebuf.Add((byte)0x07);
                filebuf.Add((byte)(filelen >> 8));
                filebuf.Add((byte)(filelen));
                for (int i = 0; i < readbuf.Length; i++)
                {
                    filebuf.Add(readbuf[i]);
                }

                fs = new FileStream(_outportfilePath + FILE_COLOR, FileMode.Open);
                readbuf = new byte[fs.Length];
                filelen = fs.Read(readbuf, 0, (int)fs.Length);
                fs.Close();

                filebuf.Add((byte)0x08);
                filebuf.Add((byte)(filelen >> 8));
                filebuf.Add((byte)(filelen));
                for (int i = 0; i < readbuf.Length; i++)
                {
                    filebuf.Add(readbuf[i]);
                }
                */

                byte[] bufwrite = new byte[filebuf.Count];
                int pos = 0;
                foreach (var item in filebuf)
                {
                    bufwrite[pos++] = (byte)(~(byte)item);
                }
                FileStream fs = new FileStream(filePath, FileMode.OpenOrCreate);
                fs.Write(bufwrite, 0, bufwrite.Length);
                fs.Close();
                return true;

            }
            catch (Exception)
            {

                return false;
            }
        }

        private static string GetFileType(FileType a)
        {
            string ret = "";
            switch (a)
            {
                case FileType.FILE_BASE:
                    ret = _outportfilePath + FILE_BASE;
                    break;
                case FileType.FILE_CLEAN:
                    ret = _outportfilePath + FILE_CLEAN;
                    break;
                case FileType.FILE_COM:
                    ret = _outportfilePath + FILE_COM;
                    break;
                case FileType.FILE_CONF:
                    ret = _outportfilePath + FILE_CONF;
                    break;
                case FileType.FILE_ID:
                    ret = _outportfilePath + FILE_ID;
                    break;
                case FileType.FILE_ING:
                    ret = _outportfilePath + FILE_ING;
                    break;
                case FileType.FILE_DRINKMAP:
                    ret = _outportfilePath + FILE_DRINKMAP;
                    break;
                case FileType.FILE_COLOR:
                    ret = _outportfilePath + FILE_COLOR;
                    break;
                default:
                    break;
            }
            return ret;
        }
        private static void FilebufMake(ref ArrayList filebuf,  FileType a)
        {
            string filePath = GetFileType(a);
            if (!filePath.Equals(""))
            {
                FileStream fs = new FileStream(filePath, FileMode.Open);
               byte[] readbuf = new byte[fs.Length];
               int filelen = fs.Read(readbuf, 0, (int)fs.Length);
                fs.Close();
                filebuf.Add((byte)a);
                filebuf.Add((byte)(filelen >> 8));
                filebuf.Add((byte)(filelen));
                for (int i = 0; i < readbuf.Length; i++)
                {
                    filebuf.Add(readbuf[i]);
                }
            }
        }
            

        private void AnalyInbuf(byte[] indat, int index)
       {
           
       }
       public static bool ImpportDB(string filePath,string folder="./config/")
       {
           if (!Directory.Exists(folder))
           {
               Directory.CreateDirectory(folder);
           }
           try
           {
              FileStream fs = new FileStream(filePath, FileMode.Open);
              byte[] inbuf = new byte[fs.Length];
              fs.Read(inbuf, 0, inbuf.Length);
              fs.Close();
              for (int i = 0; i < inbuf.Length; i++)
              {
                  inbuf[i] =(byte)(~inbuf[i]);
              }
              int pos = 0;
              //TODO:文件有效性检查
              byte filetype = 0;
              UInt16 fileLen = 0;
              byte[] writebuf;
              int filepos = 3;
              do
              {
                  filetype = inbuf[pos++];
                  fileLen = (UInt16)((inbuf[pos++] << 8) + (inbuf[pos++]));
                  writebuf = new byte[fileLen];
                  Array.Copy(inbuf, filepos, writebuf, 0, fileLen);
                  filepos = filepos + fileLen + 3;
                  pos += fileLen;
                  FileType tmp = (FileType)filetype;
                  //FileStream fs;
                  string filepath = string.Empty;
                  switch (tmp)
                  {
                      case FileType.FILE_BASE:
                          filepath = folder + FILE_BASE;
                          break;
                      case FileType.FILE_CLEAN:
                          filepath = folder + FILE_CLEAN;
                          break;
                      case FileType.FILE_COM:
                          filepath = folder + FILE_COM;
                          break;
                      case FileType.FILE_CONF:
                          filepath = folder + FILE_CONF;
                          break;
                      case FileType.FILE_ID:
                          filepath = folder + FILE_ID;
                          break;
                      case FileType.FILE_ING:
                          filepath = folder + FILE_ING;
                          break;
                        case FileType.FILE_DRINKMAP:
                            filepath = folder + FILE_DRINKMAP;
                            break;
                        case FileType.FILE_COLOR:
                            filepath = folder + FILE_COLOR;
                            break;
                      default:
                          break;
                  }
                  if (filepath != string.Empty)
                  {
                      fs = new FileStream(filepath, FileMode.Create);
                      fs.Write(writebuf, 0, fileLen);
                      
                      fs.Close();
                  }

              } while (pos < inbuf.Length);
              return true;
           }
           catch (Exception)
           {
               return false;
           }

       }
    }

    //BASE  
    //CLEAN 
    //COM = 
    //CONF =
    //ID = "
    //ING = 
   public enum FileType
   {
       FILE_BASE =1,
       FILE_CLEAN,
       FILE_COM,
       FILE_CONF,
       FILE_ID,
       FILE_ING,
       FILE_DRINKMAP,
       FILE_COLOR
   }
}
