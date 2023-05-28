//
//  Register2ViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import UIKit
import FirebaseAuth
import FirebaseDatabase

class Register2ViewController: UIViewController {

    @IBOutlet weak var registerButtonEdit: DefaultButton!
    @IBOutlet weak var emailTF: DefaultTextField!
    @IBOutlet weak var pwTF: DefaultTextField!
    @IBOutlet weak var alreadyHasAccountEdit: UIButton!
    
    var auth: Auth?
        
    override func viewDidLoad() {
        super.viewDidLoad()
        setupPWTextFields()
        setupToolBar()
        registerButtonEdit.isEnabled = true
        registerButtonEdit.configure(whatsInside: "Registrar")
        navigationHiddens()
        self.auth = Auth.auth()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        if UserDefaults.standard.bool(forKey: "logado") {
            self.dismiss(animated: false)
        }
    }
    
    private func navigationHiddens() {
        self.navigationController?.setNavigationBarHidden(true, animated: false)
        self.tabBarController?.tabBar.isHidden = true
    }
    
    private func setupPWTextFields() {
        pwTF.isSecureTextEntry = true
    }
    
    func uploadToDataBase(email: String, onSuccess: @escaping () -> Void) {
        let ref = Database.database().reference()
        let uid = Auth.auth().currentUser?.uid
        
        ref.child("users").child(uid!).setValue(["email": email])
        
        ref.child("users").child(uid!).child("assets").child("fii").child("inTotal").setValue(0)
        ref.child("users").child(uid!).child("assets").child("acoes").child("inTotal").setValue(0)
        ref.child("users").child(uid!).child("assets").child("cripto").child("inTotal").setValue(0)
        ref.child("users").child(uid!).child("assets").child("totalCarteira").setValue(0)
        
        onSuccess()
    }
        
    @IBAction func sendUser(_ sender: Any) {
        let email: String = self.emailTF.text ?? ""
        let pw: String = self.pwTF.text ?? ""
        
        auth?.createUser(withEmail: email, password: pw, completion: { result, error in
            if error != nil {
                let alert = UIAlertController(title: "Erro", message: error.debugDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Ok", style: .destructive, handler: nil))
                self.present(alert, animated: true)
            } else {
                self.uploadToDataBase(email: email, onSuccess: self.printToDatabase)
                let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
                    self.navigationController?.popToRootViewController(animated: true)
                }))
                self.present(alert, animated: true)
            }
        })
    }
    
    @IBAction func AlreadyHasAccount(_ sender: Any) {
        let myViewController = LoginViewController()
        navigationController?.pushViewController(myViewController, animated: false)
    }
    
    func printToDatabase() {
        print("In database!\n")
    }
    
    func setupToolBar() {
        setupToolBarPW()
        setupToolBarEmail()
    }
    
    private func setupToolBarEmail() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemEmail = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardEmail))
        let nextButtonItemEmail = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldEmail))
        keyboardToolbar.items = [flexBarButton, closeButtonItemEmail, nextButtonItemEmail]
        emailTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarPW() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemPW = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardPW))
        keyboardToolbar.items = [flexBarButton, closeButtonItemPW]
        pwTF.inputAccessoryView = keyboardToolbar
    }
    
    
    @objc func closeKeyboardEmail() {
        emailTF.endEditing(true)
    }
    
    @objc func closeKeyboardPW() {
        pwTF.endEditing(true)
    }
    
    @objc func nextTextFieldEmail() {
        emailTF.resignFirstResponder()
        pwTF.becomeFirstResponder()
    }
}
