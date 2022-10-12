//
//  Register2ViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import UIKit
import FirebaseAuth

protocol ServiceDelegate {
    func dataSucess()
    func dataFail(error: Error)
    func showLoad()
    func removeLoad()
}

class Register2ViewController: UIViewController {

    @IBOutlet weak var registerButtonEdit: DefaultButton!
    @IBOutlet weak var emailTF: DefaultTextField!
    @IBOutlet weak var pwTF: DefaultTextField!
    @IBOutlet weak var alreadyHasAccountEdit: UIButton!
    
    var auth: Auth?
    
    @IBAction func AlreadyHasAccount(_ sender: Any) {
        let myViewController = LoginViewController()
        navigationController?.pushViewController(myViewController, animated: false)
    }
    
    private var viewModel: Register2ViewModel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupPWTextFields()
        setupToolBar()
        registerButtonEdit.isEnabled = true
        registerButtonEdit.configure(whatsInside: "Registrar")
        navigationHiddens()
        self.auth = Auth.auth()
    }
    
    private func navigationHiddens() {
        self.navigationController?.setNavigationBarHidden(true, animated: false)
        self.tabBarController?.tabBar.isHidden = true
    }
    
    override func viewDidAppear(_ animated: Bool) {
        if UserDefaults.standard.bool(forKey: "logado") {
            self.dismiss(animated: false)
        }
    }
    
    private func setupPWTextFields() {
        pwTF.isSecureTextEntry = true
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
                let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
                    self.navigationController?.popToRootViewController(animated: true)
                }))
                self.present(alert, animated: true)
            }
        })
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
